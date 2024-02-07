from django.contrib.auth.models import AbstractUser
from django.db import models


class Bid(models.Model):
    price = models.DecimalField(max_digits=8, decimal_places=2)
    listing_id = models.ForeignKey("Listing", on_delete=models.CASCADE, related_name="listing_bids")
    user_id = models.ForeignKey("User", on_delete=models.CASCADE, related_name="user_bids")


class Comment(models.Model):
    content = models.TextField(max_length=256)
    listing_id = models.ForeignKey("Listing", on_delete=models.CASCADE, related_name="listing_comments")
    user_id = models.ForeignKey("User", on_delete=models.CASCADE, related_name="user_comments")


class Listing(models.Model):
    ELECTRONICS = "electronics"
    FASHION = "fashion"
    FOOD = "food"
    HOBBIES = "hobbies"
    HOME = "home"
    MEDIA = "media"
    TOYS = "toys"
    CATEGORIES = [
        ("", "No category"),
        (ELECTRONICS, "Electronics"),
        (FASHION, "Fashion"),
        (FOOD, "Food"),
        (HOBBIES, "Hobbies"),
        (HOME, "Home"),
        (MEDIA, "Media"),
        (TOYS, "Toys")
    ]

    title = models.CharField(max_length=64)
    description = models.TextField(max_length=256)
    category = models.CharField(blank=True, choices=CATEGORIES, default="", max_length=64)
    image = models.URLField(blank=True)
    starting_bid = models.DecimalField(max_digits=8, decimal_places=2)
    time = models.DateTimeField(auto_now=True)
    status = models.CharField(default="open", max_length=8)
    user_id = models.ForeignKey("User", on_delete=models.CASCADE, related_name="listings")


class User(AbstractUser):
    watchlist = models.ManyToManyField(Listing, blank=True, related_name="users_watchlisted")
