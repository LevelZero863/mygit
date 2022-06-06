import base64
import json
import time

import copyheaders
import requests

headers = copyheaders.headers_raw_to_dict(b"""
accept: */*
accept-language: zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6
authorization: Bearer -8T8NPL3-7GjwkHCMb5x8Mk2MvHq3JQ
cache-control: no-cache
content-length: 443
content-type: application/json
origin: https://www.reddit.com
pragma: no-cache
referer: https://www.reddit.com/
sec-ch-ua: " Not A;Brand";v="99", "Chromium";v="101", "Microsoft Edge";v="101"
sec-ch-ua-mobile: ?0
sec-ch-ua-platform: "Windows"
sec-fetch-dest: empty
sec-fetch-mode: cors
sec-fetch-site: same-site
user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/101.0.4951.54 Safari/537.36 Edg/101.0.1210.39
x-reddit-loid: 0000000000n1nrbgu2.2.1652410518000.Z0FBQUFBQmlmY2lXdHNfWFZKcTBxN2JGTFhEUHZJZEYzSXYxNHo2T1hRUkNpczU4MzZ0aVlMempUbV9DV2E1aFAzbnlWSW9JcFZXQVdhdHkzRHhqbWhIdnR4NWpyNWJHaW9YRXlQd0NLOGhRUVJLeHhmMVFVcEQ2ZE5mM1ZQYTlfSlhnbTJ5SmtTdEs
x-reddit-session: oeeganihaoolpcaifb.0.1652410525829.Z0FBQUFBQmlmY2lkRnB5R0FmeHYtUUxCU3JUQkxqbVRJdmczSFFEeVNJLW01aWR0VFVOb1BpVWU1Ui1LSVp5RXBrUFZlaVF4MkxJTnFkaFB4N1pneGNQaWh0QmdJY1RpOEE2dU16TzdBbUJ4YnVXa0psVEgxbXpVcVNKQ0lkbnRKS0RkaHFLc1F5Sno
""")




def download_kw(kw):
    print(f">>>正在访问关键字：{kw}")
    for page in range(10):
        count = page*25
        data = '{"id":"3f17a00e7140",' \
               '"variables":{' \
               f'"query":"{kw}",' \
               '"sort":null,' \
               '"filters":[{"key":"nsfw","value":"0"}],' \
               '"productSurface":"web2x",' \
               '"includePosts":true,' \
               '"includeCommunities":false,"includeAuthors":false,' \
               '"includeComments":false,' \
               '"postsAfter":"'+base64.b64encode(str(count).encode()).decode()+'","communitiesAfter":null,' \
               '"authorsAfter":null,"commentsAfter":null,"searchInput":' \
               '{"queryId":"9316d39b-7ecc-4109-b45d-d95743bfb29c","structureType":' \
               '"search"},"communitySearch":false,"customFeedSearch":false}}'
        while True:
            try:
                res = requests.post('https://gql.reddit.com/', data=data, headers=headers).json()
                break
            except Exception as e:
                print(f">>>kws: {kw} page: {page} error: {e}")
                time.sleep(2)
        cms_list = res.get("data").get("search").get("general").get("posts").get("edges")
        print(kw,page,len(cms_list))
        for itemc in cms_list:
            item = itemc.get("node")
            saveitem = {}
            saveitem["keyword"] = kw
            saveitem["cmsid"] = item.get("id")
            saveitem["createdAt"] = item.get("createdAt")
            saveitem["title"] = item.get("title")
            saveitem["commentCount"] = item.get("commentCount")
            saveitem["crosspostCount"] = item.get("crosspostCount")
            saveitem["score"] = item.get("score")
            print(kw,page,saveitem)
            with open("demo2.txt",'a',encoding='utf-8') as ff:
                ff.write(json.dumps(saveitem))
                ff.write('\n')











if  __name__ == '__main__':




    # with open("./source/kws2.txt",'r',encoding='utf-8' ) as ff:
    #     kws = [i.strip() for i in ff.readlines() if i.strip() != '']

    ikw = "touch"
    # for ikw in kws[70:]:
    download_kw(ikw)

        # try:
        #     download_kw(ikw)
        # except Exception as e:
        #     print(f">>>error: {e}")
        #     time.sleep(1)
