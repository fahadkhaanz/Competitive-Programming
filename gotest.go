package main

import "fmt"

func main(){
	var t int
	fmt.Scanf("%d",&t)
	for t>0{
		t--
		var n,p,k int
		fmt.Scan(&n,&p,&k)
		ans:=0
		mod:=p%k
        ans=(mod)*((n)/k)+1+p/k
		fmt.Println(ans)
	}
	
}