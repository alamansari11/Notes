
`docker pull redis`

This will download the latest official Redis image from Docker Hub.

---

#### **2. Run the Redis Container**

To run the Redis container, execute:

bash

Copy code

`docker run --name my-redis -d -p 6379:6379 redis`

docker exec -it my-redis redis-cli
127.0.0.1:6379> ping
PONG
127.0.0.1:6379> KEYS *
(empty array)
127.0.0.1:6379> SCAN 0
1) "0"
2) (empty array)
127.0.0.1:6379>



 KEYS *
1) "4866f0ff-1c95-4aed-a970-0d1ee4579790"

127.0.0.1:6379> GET "4866f0ff-1c95-4aed-a970-0d1ee4579790"


"{\"partnerId\":\"ril\",\"partnerUserId\":\"55053414\",\"ssoToken\":\"4866f0ff-1c95-4aed-a970-0d1ee4579790\",\"expiresAt\":null}"


127.0.0.1:6379> ACL GETUSER root
(nil)
127.0.0.1:6379> ACL GETUSER admin
(nil)
127.0.0.1:6379> ACL LIST
1) "user default on nopass sanitize-payload ~* &* +@all"
127.0.0.1:6379> ACL SETUSER default on >root ~* +@all
OK
127.0.0.1:6379> ACL LIST
1) "user default on sanitize-payload #4813494d137e1631bba301d5acab6e7bb7aa74ce1185d456565ef51d737677b2 ~* &* +@all"
127.0.0.1:6379> ACL GETUSER default