package res

import "runtime"

var winEnter = "\r\n"
var macEnter = "\n"

var Enter string

func SetOSType()  {
	os := runtime.GOOS
	if os == "darwin" {
		Enter = macEnter
	}
	if os == "windows" {
		Enter = winEnter
	}
}