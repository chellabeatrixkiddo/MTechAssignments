import tweepy
import json

CONSUMER_KEY = 'UKbRRwBrmbNJe99x7AUilL7lm'
CONSUMER_SECRET = 'YvdWDgRSMpxknxEKBz7LrSZjcR1CkKPgdDaIft4NjpngIobfmD'
ACCESS_KEY = '855282597085069312-VrXGJQONyrk9V43EtnqV9LjbZaVbOde'
ACCESS_SECRET = 'LyS1w3VINgqbhA8JqW3rOfCAWefOByc0YbjcFw2y8zucy'

auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)
api = tweepy.API(auth, parser=tweepy.parsers.JSONParser())

search_texts = ["#garbageBBMP", "#adminBBMP"]
depmt = ["garbage", "admin"]
userinfo = {}
key1 = "name"
key2 = "location"
key3 = "dept"

for i in range(0, 2):
    search_result = api.search(search_texts[i], count = 1)
    if search_result is None:
        continue
    else:
        api.retweet(search_result.id) # retweet
        user_details = api.get_user(user_id=search_result.from_user_id) 
        userinfo.clear()
        userinfo[key1] = user_details.screen_name
        userinfo[key2] = user_details.location
        userinfo[key2] = depmt
        sn = i.user.screen_name
        m = "@%s Hello! We will resolve your complaint" % (sn)
        

