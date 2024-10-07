package main // Every Go program starts with a package declaration. "main" is the entry point for an executable program.

import (
	"fmt"  // "fmt" is a package for formatted I/O.
	"math" // "math" provides basic constants and mathematical functions.
)

// Constants in Go
const Pi = 3.14

// Variables can be declared globally or locally
var globalVar int = 10

func main() {
	// Variable declarations
	var a int = 5         // Explicit type
	b := 10               // Implicit type (type inference)
	var c, d int = 15, 20 // Multiple variables of the same type

	// Strings
	name := "Go Language" // String declaration

	// Constants
	const greeting = "Hello"

	// Printing variables and strings
	fmt.Println(greeting, name)
	fmt.Println("Value of a:", a)
	fmt.Println("Value of b:", b)
	fmt.Println("Value of c and d:", c, d)

	// Control structures: if-else
	if a < b {
		fmt.Println("a is less than b")
	} else {
		fmt.Println("a is greater than or equal to b")
	}

	// Loops: for (Go only has "for" loops, no while or do-while)
	for i := 0; i < 5; i++ {
		fmt.Println("Loop index:", i)
	}

	// Arrays
	var arr [3]int = [3]int{1, 2, 3}
	fmt.Println("Array elements:", arr)

	// Slices (dynamic arrays)
	slice := []int{4, 5, 6, 7}
	fmt.Println("Slice elements:", slice)

	// Appending to slices
	slice = append(slice, 0, 8, 9)
	fmt.Println("Appended slice:", slice)

	// Maps (key-value pairs)
	myMap := map[string]int{
		"one": 1,
		"two": 2,
	}
	fmt.Println("Map elements:", myMap)

	// Functions
	result := add(3, 4) // Call the add function
	fmt.Println("Result of addition:", result)

	// Pointers
	var ptr *int = &a // Pointer to variable a
	fmt.Println("Value of a through pointer:", *ptr)

	// Structs (custom data types)
	type Person struct {
		name string
		age  int
	}

	person := Person{name: "John", age: 30}
	fmt.Println("Person:", person.name, "is", person.age, "years old")

	// Interface and polymorphism
	var shape Shape = Circle{radius: 5}
	fmt.Println("Area of the shape:", shape.Area())

	// Error handling (error is a built-in type)
	sqrt, err := sqrt(16)
	if err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Println("Square root:", sqrt)
	}

	// Defer (postpones the execution of a function until the surrounding function returns)
	defer fmt.Println("Deferred message 1")
	fmt.Println("Main function ends")
	defer fmt.Println("Deferred message 2") // Deferred messages are executed in LIFO order
}

// Function declaration (named return values)
func add(x, y int) int {
	return x + y
}

// Interface (defines a method set)
type Shape interface {
	Area() float64
}

// Struct implementing an interface
type Circle struct {
	radius float64
}

// Method with receiver (attaches a function to a struct type)
func (c Circle) Area() float64 {
	return Pi * c.radius * c.radius
}

// Function returning multiple values (including an error)
func sqrt(x float64) (float64, error) {
	if x < 0 {
		return 0, fmt.Errorf("cannot compute square root of a negative number")
	}
	return math.Sqrt(x), nil
}
