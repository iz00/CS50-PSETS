from decimal import Decimal
from django import forms
from django.forms import ModelForm
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from django.db import IntegrityError
from django.http import HttpResponseRedirect
from django.shortcuts import render
from django.urls import reverse

from .models import *


class CreateListingForm(ModelForm):
    starting_bid = forms.DecimalField(decimal_places=2, label="Starting bid", label_suffix=": $", max_digits=64, min_value=Decimal("0.01"), step_size=0.01, widget=forms.NumberInput(attrs={"placeholder": "000.00"}))
    class Meta:
        model = Listing
        fields = ["title", "description", "starting_bid", "image", "category"]
        widgets = {
            "description": forms.Textarea(attrs={"autocomplete":"off", "cols": 80, "placeholder": "Enter the listing's description here.", "rows": 5}),
            "image": forms.TextInput(attrs={"autocomplete":"off", "placeholder": "https://example.com"}),
            "title": forms.TextInput(attrs={"autocomplete":"off", "placeholder": "Enter the listing's title here."})
        }


def index(request):
    return render(request, "auctions/index.html", {
        "listings": Listing.objects.all().order_by("-time")
    })


@login_required
def create(request):
    if request.method == "GET":
        return render(request, "auctions/create.html", {
            "form": CreateListingForm()
        })

    form = CreateListingForm(request.POST)

    if not form.is_valid():
        return render(request, "auctions/create.html", {
            "form": form
        })

    Listing(
        category=form.cleaned_data["category"],
        description=form.cleaned_data["description"].capitalize(),
        image=form.cleaned_data["image"],
        starting_bid=Decimal(form.cleaned_data["starting_bid"]),
        status="open",
        title=form.cleaned_data["title"].title(),
        lister=User.objects.get(pk=request.user.id)
    ).save()

    return HttpResponseRedirect(reverse("index"))


def login_view(request):
    if request.method == "GET":
        return render(request, "auctions/login.html", {
            "next_page": f"{request.GET.get('next', '')}"
        })

    # Attempt to sign user in
    username = request.POST["username"]
    password = request.POST["password"]
    user = authenticate(request, username=username, password=password)

    # Check if authentication successful
    if user:
        login(request, user)

        next_page = request.POST["next_page"]

        if next_page:
            return HttpResponseRedirect(f"{next_page}")

        return HttpResponseRedirect(reverse("index"))

    return render(request, "auctions/login.html", {
        "message": "Invalid username and/or password."
    })


def logout_view(request):
    logout(request)
    return HttpResponseRedirect(reverse("index"))


def register(request):
    if request.method == "GET":
        return render(request, "auctions/register.html")

    username = request.POST["username"]
    email = request.POST["email"]

    # Ensure password matches confirmation
    password = request.POST["password"]
    confirmation = request.POST["confirmation"]
    if password != confirmation:
        return render(request, "auctions/register.html", {
            "message": "Passwords must match."
        })

    # Attempt to create new user
    try:
        user = User.objects.create_user(username, email, password)
        user.save()
    except IntegrityError:
        return render(request, "auctions/register.html", {
            "message": "Username already taken."
        })

    login(request, user)
    return HttpResponseRedirect(reverse("index"))
