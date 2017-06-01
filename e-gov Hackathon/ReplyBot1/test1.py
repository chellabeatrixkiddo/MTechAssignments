import tweepy

CONSUMER_KEY = 'UKbRRwBrmbNJe99x7AUilL7lm'
CONSUMER_SECRET = 'YvdWDgRSMpxknxEKBz7LrSZjcR1CkKPgdDaIft4NjpngIobfmD'
ACCESS_KEY = '855282597085069312-VrXGJQONyrk9V43EtnqV9LjbZaVbOde'
ACCESS_SECRET = 'LyS1w3VINgqbhA8JqW3rOfCAWefOByc0YbjcFw2y8zucy'

auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)
api = tweepy.API(auth, parser=tweepy.parsers.JSONParser())

search_text = "#complaintBBMP"
search_result = api.search(search_text)
userinfo = {}
key1 = "name"
key2 = "location"
key3 = "dept"

for i in search_result:
    #auto retweet the user's complaint
    api.retweet(i.id)
    sn = i.user.screen_name
    user_details = api.get_user(user_id=i.from_user_id)
    
    #logic to check for the department
    
    #user details: name, location, dept
    userinfo.clear()
    userinfo[key1] = user_details.screen_name
    userinfo[key2] = user_details.location
    userinfo[key2] = dept
    
    #send the user details and get the url of the pre-filled form
    url = form_details(userinfo)
    
    #auto reply with the form link
    m = "@%s Please fill the form to register a complaint: %s" % (sn, url)
    

    
