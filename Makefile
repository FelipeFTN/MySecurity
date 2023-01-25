prog: app/app.h app/app.c main.go
	go build -o MySecurity 
clean:
	rm -rf MySecurity 
