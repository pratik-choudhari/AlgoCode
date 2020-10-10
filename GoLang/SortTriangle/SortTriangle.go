package main

import (
	"fmt"
	"math"
)

func main() {
	var totalTriangle int
	var inputBuffer float64
	fmt.Scan(&totalTriangle)
	var triangles = make([][]float64, 0)
	for i := 0; i < totalTriangle; i++ {
		tmp := make([]float64, 0)
		for j := 0; j < 3; j++ {
			fmt.Scan(&inputBuffer)
			tmp = append(tmp, inputBuffer)
		}
		triangles = append(triangles, tmp)
	}
	sort(&triangles, totalTriangle)
	print(triangles, totalTriangle)
}

func area(triangles []float64) float64 {
	a := triangles[0]
	b := triangles[0]
	c := triangles[0]
	p := (a + b + c) / 2
	var areaPower float64 = p * ((p - triangles[0]) * (p - triangles[0]) * (p - triangles[0]))
	return math.Sqrt(areaPower)
}

// buble sort
func sort(triangles *[][]float64, n int) {
	for i := 0; i < n-1; i++ {
		for j := 0; j < n-i-1; j++ {
			if area((*triangles)[j]) > area((*triangles)[j+1]) {
				var temp []float64
				temp = (*triangles)[j+1]
				(*triangles)[j+1] = (*triangles)[j]
				(*triangles)[j] = temp
			}
		}
	}
}

func print(triangles [][]float64, n int) {
	for i := 0; i < n; i++ {
		for j := 0; j < 3; j++ {
			fmt.Print(math.Trunc(triangles[i][j]))
			fmt.Print(" ")
		}
		fmt.Print("\n")
	}
}
