package main

import (
	"fmt"
	"sync"
	"time"
)

// Constants and iota
const (
	Read    = 1 << iota // 1
	Write               // 2
	Execute             // 4
)

// Struct embedding (composition)
type Animal struct {
	Name string
}

func (a Animal) Speak() {
	fmt.Println("Animal speaks")
}

// Dog struct embeds Animal (composition)
type Dog struct {
	Animal
	Breed string
}

func (d Dog) Speak() {
	fmt.Println("Dog barks")
}

// Interface with multiple methods
type Geometry interface {
	Area() float64
	Perimeter() float64
}

// Struct implementing the Geometry interface
type Rectangle struct {
	Width, Height float64
}

func (r Rectangle) Area() float64 {
	return r.Width * r.Height
}

func (r Rectangle) Perimeter() float64 {
	return 2 * (r.Width + r.Height)
}

// Goroutines (concurrent functions)
func sayHello(name string) {
	fmt.Printf("Hello, %s!\n", name)
}

// Channels (for communication between goroutines)
func sum(a []int, c chan int) {
	total := 0
	for _, v := range a {
		total += v
	}
	c <- total // send total to channel
}

// Select statement (waiting on multiple channels)
func fibonacci(c, quit chan int) {
	x, y := 0, 1
	for {
		select {
		case c <- x:
			x, y = y, x+y
		case <-quit:
			fmt.Println("quit")
			return
		}
	}
}

// Sync primitives (Mutex for safe concurrent access)
var counter int
var mutex sync.Mutex

func increment(wg *sync.WaitGroup) {
	defer wg.Done()
	mutex.Lock()
	counter++
	mutex.Unlock()
}

// Panic and recover (error handling)
func divide(a, b int) (result int, err error) {
	defer func() {
		if r := recover(); r != nil {
			err = fmt.Errorf("recovering from panic: %v", r)
		}
	}()
	if b == 0 {
		panic("division by zero")
	}
	result = a / b
	return
}

// Reflection (inspecting types at runtime)
func reflectType(x interface{}) {
	t := fmt.Sprintf("%T", x) // Get the type as a string
	fmt.Println("Type:", t)
}

// Generics (Type parameters in Go)
func find[T comparable](s []T, x T) int {
	for i, v := range s {
		if v == x {
			return i
		}
	}
	return -1
}

func main() {
	// Advanced Struct and Interface Usage
	dog := Dog{Animal: Animal{Name: "Rover"}, Breed: "Labrador"}
	dog.Speak() // Dog's Speak method overrides Animal's

	// Geometry interface example
	r := Rectangle{Width: 3, Height: 4}
	fmt.Println("Area of rectangle:", r.Area())
	fmt.Println("Perimeter of rectangle:", r.Perimeter())

	// Goroutines (concurrent functions)
	go sayHello("World")
	go sayHello("Go")

	// Channels for communication
	a := []int{1, 2, 3, 4, 5}
	c := make(chan int)
	go sum(a[:len(a)/2], c)
	go sum(a[len(a)/2:], c)
	x, y := <-c, <-c // receive from channel c
	fmt.Println("Sum of array parts:", x, y, "Total:", x+y)

	// Select statement
	fibChan := make(chan int)
	quit := make(chan int)
	go func() {
		for i := 0; i < 10; i++ {
			fmt.Println(<-fibChan)
		}
		quit <- 0
	}()
	fibonacci(fibChan, quit)

	// Using Mutex for safe concurrent access
	var wg sync.WaitGroup
	for i := 0; i < 1000; i++ {
		wg.Add(1)
		go increment(&wg)
	}
	wg.Wait()
	fmt.Println("Final counter value:", counter)

	// Panic and recover example
	result, err := divide(10, 0)
	if err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Println("Result:", result)
	}

	// Reflection example
	reflectType(42)
	reflectType("Go")

	// Using Generics
	intSlice := []int{1, 2, 3, 4, 5}
	strSlice := []string{"a", "b", "c", "d"}
	fmt.Println("Index of 3 in intSlice:", find(intSlice, 3))
	fmt.Println("Index of 'c' in strSlice:", find(strSlice, "c"))

	// Give time for goroutines to finish
	time.Sleep(1 * time.Second)
}
