from django.urls import path

from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("bid/", views.bid, name="bid"),
    path("comment/", views.comment, name="comment"),
    path("create/", views.create, name="create"),
    path("listing/<int:listing_id>", views.listing, name="listing"),
    path("login/", views.login_view, name="login"),
    path("logout/", views.logout_view, name="logout"),
    path("register/", views.register, name="register"),
    path("watchlist/", views.watchlist, name="watchlist")
]
