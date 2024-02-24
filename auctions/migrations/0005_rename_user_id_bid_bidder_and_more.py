# Generated by Django 5.0.1 on 2024-02-08 18:45

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('auctions', '0004_alter_listing_status'),
    ]

    operations = [
        migrations.RenameField(
            model_name='bid',
            old_name='user_id',
            new_name='bidder',
        ),
        migrations.RenameField(
            model_name='bid',
            old_name='listing_id',
            new_name='listing',
        ),
        migrations.RenameField(
            model_name='comment',
            old_name='user_id',
            new_name='commenter',
        ),
        migrations.RenameField(
            model_name='comment',
            old_name='listing_id',
            new_name='listing',
        ),
        migrations.RenameField(
            model_name='listing',
            old_name='user_id',
            new_name='lister',
        ),
    ]