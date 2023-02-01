obj-m +=hello.o

KDIR = /lib/modules/$(Shell uname -r)/build

all:
	make -C $(KDIR) M=$(Shell pwd) modules

clean:
	make -C $(KDIR) M=$(Shell pwd) clean
