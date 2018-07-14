// polypentec (c) 2018. All rights reserved.
package main

import (
  "fmt"
  "os"
  "os/exec"
  "path"
  "path/filepath"
  "polypentec/file"
)

type PPTC struct {
}

func NewPPTC() *PPTC {
  return &PPTC{}
}

func (cmd *PPTC) Build() {
  cmd.Reset()
  if err := exec.Command(path.Join(filepath.ToSlash(os.Getenv("GOPATH")),
    "src/dajour.christophe.org/.bin/tools/build.bat")).Run(); err != nil {
    panic(err)
  }
}

func (cmd *PPTC) Reset() {
  resources := []map[string]interface{}{
    map[string]interface{}{".ecce/bin":".exe"},
    map[string]interface{}{".ecce/cache":"*"},
    map[string]interface{}{"zmem.Resource/private/template":".min.tmpl"},
    map[string]interface{}{"zmem.Resource/public/css/":".min.css"},
    map[string]interface{}{"zmem.Resource/public/css/":".css"},
  }
  for _, resource := range resources {
    for dir, ext := range resource {
      file.RemoveAllFiles(dir, ext.(string))
    }
  }
}

func (cmd *PPTC) Start() {
  if err := exec.Command(path.Join(filepath.ToSlash(os.Getenv("GOPATH")),
    "src/dajour.christophe.org/.bin/tools/run.bat")).Run(); err != nil {
    panic(err)
  }
}

func (cmd *PPTC) Stop() {
  if err := exec.Command(path.Join(filepath.ToSlash(os.Getenv("GOPATH")),
    "src/dajour.christophe.org/.bin/tools/shutdown.bat")).Run(); err != nil {
    panic(err)
  }
}

func (cmd *PPTC) Test() {
  fmt.Println("automated testing is not supported. conduct a manual function test.")
}

func sort(p string) {
  cmd := NewPPTC()
  switch p {
  case "-build":
    cmd.Build()
    break
  case "-reset":
    cmd.Reset()
    break
  case "-start":
    cmd.Start()
    break
  case "-stop":
    cmd.Stop()
    break
  case "-test":
    cmd.Test()
    break
  default:
    break
  }
}

func main() {
  args := os.Args
  param := args[1]
  if len(args) != 2 {
    println("incorrect args")
    return
  }
  sort(param)
}
