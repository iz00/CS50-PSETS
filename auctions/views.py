from django import forms
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from django.db import IntegrityError
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render
from django.urls import reverse

from .models import *


def index(request):
    return render(request, "auctions/index.html")


@login_required
def create(request):
    if request.method == "GET":
        return render(request, "auctions/create.html")


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
