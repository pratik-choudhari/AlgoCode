package main
import "fmt"
func main() {
    n:=5
    result := util(n,2)
    if result==false{
        fmt.Printf("%v is not a Lucky number.\n",n)
    }else{
        fmt.Printf("%v is a Lucky number.\n",n)
    }
}

func util(n int, counter int) bool{
    if counter>n{
        return true
    }
    if n%counter==0{
        return false
    }
    n = n-n/counter
    return util(n,counter+1)
}