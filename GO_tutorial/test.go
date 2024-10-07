package main

import (
    "github.com/k0kubun/pp"
)

func main() {
    data := map[string]interface{}{"name": "John", "age": 30}
    pp.Println(data)
	a := 1
	pp.Println(a)
}
