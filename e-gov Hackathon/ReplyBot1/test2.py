import tweepy
import csv

CONSUMER_KEY = 'UKbRRwBrmbNJe99x7AUilL7lm'
CONSUMER_SECRET = 'YvdWDgRSMpxknxEKBz7LrSZjcR1CkKPgdDaIft4NjpngIobfmD'
ACCESS_KEY = '855282597085069312-VrXGJQONyrk9V43EtnqV9LjbZaVbOde'
ACCESS_SECRET = 'LyS1w3VINgqbhA8JqW3rOfCAWefOByc0YbjcFw2y8zucy'
auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)
api = tweepy.API(auth)

search_text = "#garbageBBMP"
search_number = 2
search_result = api.search(search_text, rpp=search_number)
for i in search_result:
    print (i.text)
    #sn = i.user.screen_name
    #m = "@%s Hello! We will resolve your complaint!" % (sn)
    #i = api.update_status(m, i.id)
    outtweets = [[tweet.id_str, tweet.created_at, tweet.text.encode("utf-8")] for tweet in i.text]
    with open('tweets.csv', 'w') as f:
        writer = csv.writer(f)
        writer.writerow(["id","created_at","text"])
        writer.writerows(outtweets)
        
    pass
