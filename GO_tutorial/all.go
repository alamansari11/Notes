package main 
//In Go, every program is part of a package. We define this using the package keyword. In this example, the program belongs to the main package.
import (
	"fmt"
	"github.com/k0kubun/pp"
	) 
//import ("fmt") lets us import files included in the fmt package.

func printVar(name string, value interface{}) {
    fmt.Printf("%s: ", name)
    pp.Println(value)
}


// In Go, statements are separated by ending a line (hitting the Enter key) or by a semicolon ";".

// Hitting the Enter key adds ";" to the end of the line implicitly (does not show up in the source code).

// The left curly bracket { cannot come at the start of a line.
func main(){
	fmt.Println("Hello")
	var student1 string = "John" // type is string
	fmt.Println(student1)
	var student2 = "John2" // type is inferred
	fmt.Println(student2)
	x := 2// type is inferred
	fmt.Println(x)
	var a string
	var b int
	var c bool
	fmt.Println(a,b,c)
// 	Difference Between var and :=
// There are some small differences between the var var :=:

// var	:=
// Can be used inside and outside of functions	Can only be used inside functions
// Variable declaration and value assignment can be done separately	Variable declaration and value assignment cannot be done separately (must be done in the same line)
   var mutli_variable_0, mutli_variable_1,mutli_variable_2  int = 1,2,3
   fmt.Println(mutli_variable_0,mutli_variable_1,mutli_variable_2)
//    Note: If you use the type keyword, it is only possible to declare one type of variable per line.

// If the type keyword is not specified, you can declare different types of variables in the same line:
//  var a, b = 6, "Hello"
//   c, d := 7, "World!"
const constname int = 2
printVar("constname", constname)

//to print the value and type of a variable
// fmt.Printf("i has value: %v and type: %T\n", i, i)

//arrays
var arr1 = [3]int{1,2,3}
  arr2 := [5]int{4,5,6,7,8}
  printVar("arr1",arr1)
  printVar("arr2",arr2)

  var arr3 = [...]int{1,2,3}
  arr4 := [...]int{4,5,6,7,8}

  printVar("arr3",arr3)
  printVar("arr4",arr4)
  myslice1 := []int{1,2,3}
  myslice2 := []int{4,5,6}
  myslice3 := append(myslice1, myslice2...)
  fmt.Printf("myslice3=%v\n", myslice3)
  fmt.Printf("length=%d\n", len(myslice3))
  fmt.Printf("capacity=%d\n", cap(myslice3))
}
