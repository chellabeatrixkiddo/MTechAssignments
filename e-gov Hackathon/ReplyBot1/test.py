import tweepy
from keys import keys
 
CONSUMER_KEY = keys['consumer_key']
CONSUMER_SECRET = keys['consumer_secret']
ACCESS_TOKEN = keys['access_token']
ACCESS_TOKEN_SECRET = keys['access_token_secret']
 
auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
auth.set_access_token(ACCESS_TOKEN, ACCESS_TOKEN_SECRET)
api = tweepy.API(auth)

while 1:
    twt = api.search(q="Jyo_Test_1")     
 
    #list of specific strings we want to check for in Tweets
    t = ['Jyo_Test_1']
        

    for s in twt:
        for i in t:
            if i == s.text:
                sn = s.user.screen_name
                m = "@%s Hello! We will resolve your complaint" % (sn)
                s = api.update_status(m, s.id)
