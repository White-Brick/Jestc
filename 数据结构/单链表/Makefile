src = $(wildcard ./src/*.c)        
obj = $(patsubst ./src/%.c, ./obj/%.o, $(src))  

target=./bin/a.out
all:$(target)

$(target):$(obj)
	gcc $(^) -o $(@)   

$(obj):./obj/%.o:./src/%.c
	gcc -c $(^) -I ./include -o $(@) -g
	
.PHONY:clean all
clean:
	-rm -rf $(target) $(obj)

	
	
	