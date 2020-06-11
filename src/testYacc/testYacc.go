package main

import (
	"SeuYacc"
	"crypto/sha1"
	"fmt"
)

func main() {
	SeuYacc.Yacc("./input/c99.y")
	//test()
}

func test()  {
	s1:="1-0-37•10-0-37•11-0-37•12-0-37•13-0-37•137-0-17•138-0-17•139-0-17•14-0-37•145-2-31•146-2-31•147-2-31•148-2-31•149-2-31•150-2-31•151-2-31•152-2-31•160-0-17•161-0-17•17-0-31•18-0-31•19-0-31•2-0-37•20-0-31•21-0-31•22-0-31•23-0-13•24-0-13•25-0-13•26-0-13•27-0-13•28-0-13•29-0-20•3-0-37•30-0-20•31-0-20•32-0-20•33-0-20•34-0-20•35-0-17•36-0-17•37-0-17•38-0-15•39-0-15•4-0-37•40-0-15•41-0-13•42-0-13•43-0-13•44-0-13•45-0-13•46-0-9•47-0-9•48-0-9•49-0-7•5-0-37•50-0-7•51-0-6•52-0-6•53-0-5•54-0-5•55-0-4•56-0-4•57-0-3•58-0-3•59-0-1•6-0-37•60-0-1•61-0-1•62-0-1•7-0-37•8-0-37•9-0-37"
	//s2:="1-0-37•10-0-37•11-0-37•12-0-37•13-0-37•137-0-17•138-0-17•139-0-17•14-0-37•145-2-31•146-2-31•147-2-31•148-2-31•149-2-31•150-2-31•151-2-31•152-2-31•160-0-17•161-0-17•17-0-31•18-0-31•19-0-31•2-0-37•20-0-31•21-0-31•22-0-31•23-0-13•24-0-13•25-0-13•26-0-13•27-0-13•28-0-13•29-0-20•3-0-37•30-0-20•31-0-20•32-0-20•33-0-20•34-0-20•35-0-17•36-0-17•37-0-17•38-0-15•39-0-15•4-0-37•40-0-15•41-0-13•42-0-13•43-0-13•44-0-13•45-0-13•46-0-9•47-0-9•48-0-9•49-0-7•5-0-38•50-0-7•51-0-6•52-0-6•53-0-5•54-0-5•55-0-4•56-0-4•57-0-3•58-0-3•59-0-1•6-0-37•60-0-1•61-0-1•62-0-1•7-0-37•8-0-37•9-0-37"
	t := sha1.New()
	t.Write([]byte(s1))
	x := t.Sum(nil)
	fmt.Println(string(x))
}
