@echo off
go build -x -v -o "C:/Users/Da'Jour Christophe/go/src/zmem/.ecce/bin/zmem.exe" "C:/Users/Da'Jour Christophe/go/src/dajour.christophe.org/out/main.go"
cd "zmem.Resource/public/"
node "index.js"
cd "../../"
