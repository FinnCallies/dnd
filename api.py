import requests
import json


response = requests.get("https://www.dnd5eapi.co/api/monsters/")
# print(response.json())

data = response.json()
monsters = data["results"]

# print(monsters)

for m in monsters:
    r = requests.get("https://www.dnd5eapi.co/api/monsters/{}".format(m["index"]))
    # print(r.status_code)
    d = r.json()
    if d["challenge_rating"] <= 1 and d["type"] != "beast":
        print(d["name"])
