from django.contrib.auth.models import AbstractUser
from django.db import models


class Bid(models.Model):
    price = models.DecimalField(max_digits=8, decimal_places=2)
    listing = models.ForeignKey("Listing", on_delete=models.CASCADE, related_name="listing_bids")
    bidder = models.ForeignKey("User", on_delete=models.CASCADE, related_name="user_bids")


    def __str__(self):
        return f"{self.price} bid by {self.bidder} made on {self.listing}"


class Comment(models.Model):
    content = models.TextField(max_length=256)
    listing = models.ForeignKey("Listing", on_delete=models.CASCADE, related_name="listing_comments")
    commenter = models.ForeignKey("User", on_delete=models.CASCADE, related_name="user_comments")


    def __str__(self):
        return f"{self.content} comment by {self.commenter} made on {self.listing}"


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

    STATUS = {
        "open": "Open",
        "closed": "Closed"
    }

    title = models.CharField(max_length=64, unique=True)
    description = models.TextField(max_length=256)
    category = models.CharField(blank=True, choices=CATEGORIES, default="", max_length=64)
    image = models.URLField(blank=True)
    starting_bid = models.DecimalField(max_digits=8, decimal_places=2)
    time = models.DateTimeField(auto_now=True)
    status = models.CharField(blank=False, choices=STATUS, default="open", max_length=8)
    lister = models.ForeignKey("User", on_delete=models.CASCADE, related_name="listings")


    def __str__(self):
        return f"{self.title} listing listed by {self.lister}"


class User(AbstractUser):
    watchlist = models.ManyToManyField(Listing, blank=True, related_name="users_watchlisted")


    def __str__(self):
        return f"{self.username}"
