from django.http import HttpResponseRedirect
from django.shortcuts import render
from django.urls import reverse

from . import util


def index(request):
    return render(request, "encyclopedia/index.html", {
        "entries": util.list_entries()
    })

def entry(request, title):
    entries = util.list_entries()
    entries_capitalized = [entry.upper() for entry in entries]
    title = title.upper()

    if title not in entries_capitalized:
        return render(request, "encyclopedia/error.html", {
            "message": "invalid entry"
        })
    
    title = entries[entries_capitalized.index(title)]

    return render(request, "encyclopedia/entry.html", {
        "title": title,
        "content": util.get_entry(title)
    })

def search(request):
    query = request.GET.get('q').upper()
    entries = util.list_entries()
    entries_capitalized = [entry.upper() for entry in entries]

    if query in entries_capitalized:
        return HttpResponseRedirect(reverse("entry", kwargs={"title": query}))

    matches = []

    for entry in entries_capitalized:
        if query in entry:
            matches.append(entries[entries_capitalized.index(entry)])

    if matches:
        return render(request, "encyclopedia/search.html", {
            "entries": matches
        })

    return render(request, "encyclopedia/error.html", {
        "message": "no matching entries"
    })
