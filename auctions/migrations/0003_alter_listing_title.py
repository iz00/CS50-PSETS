# Generated by Django 5.0.1 on 2024-02-08 18:30

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('auctions', '0002_listing_comment_bid_user_watchlist'),
    ]

    operations = [
        migrations.AlterField(
            model_name='listing',
            name='title',
            field=models.CharField(max_length=64, unique=True),
        ),
    ]