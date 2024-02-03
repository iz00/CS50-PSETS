from django.shortcuts import render

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
