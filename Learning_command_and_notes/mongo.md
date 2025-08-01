To query documents where the size of the `providers_info` array is **not equal to 1**, you can use the `$expr` operator with the `$not` and `$eq` operators in MongoDB. Here's the correct query:
{
  $expr: { $eq: [{ $size: "$providers_info" }, 1] }
}




If you are trying to match documents where `providers_info` is an array of size 2:

javascript

Copy code

`{ providers_info: { $size: 2 } }`


docker run -d --name mongodb -p 27017:27017 -v mongodata:/data/db -e MONGO_INITDB_ROOT_USERNAME=mongoadmin -e MONGO_INITDB_ROOT_PASSWORD=secret mongo


-d detached mode means it would keep running in the background and control get back to terminal

copy one collection and create new one

db["packages"].aggregate([{$match: {}},{$out: "packages_backup_1"}])