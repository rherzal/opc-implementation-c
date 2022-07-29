node: node.c
	gcc node.c -c -lm

reward: reward.c 
	gcc reward.c -c
xplus: xplus.c
	gcc xplus.c -c -lm

opd: opd.c node reward xplus
	gcc opd.c node.o reward.o xplus.o -c

main: opd main.c 
	gcc main.c opd.o node.o reward.o xplus.o -o main -lm