from turtle import *

def stop():
    global running
    running = False

def main():
    global running
    clearscreen()
    bgcolor("gray10")
    tracer(False)
    shape("triangle")
    f =   0.793402
    phi = 9.064678
    s = 5
    c = 1
    # create compound shape
    sh = Shape("compound")
    for i in range(10):
        shapesize(s)
        p =get_shapepoly()
        s *= f
        c *= f
        tilt(-phi)
        sh.addcomponent(p, (c, 0.45, 1-c), "black")
    register_shape("multitri", sh)
    # create dancers
    shapesize(1)
    shape("multitri")
    pu()
    setpos(0, -100)
    dancers = []
    for i in range(90):
        fd(7)
        tilt(-50)
        lt(5)
        update()
        if i % 4 == 0:
            dancers.append(clone())
    home()
    # dance
    running = True
    onkeypress(stop)
    listen()
    cs = 1
    while running:
        ta = -6
        for dancer in dancers:
            dancer.fd(6)
            dancer.lt(2)
            dancer.tilt(ta)
            ta = -6 if ta > 0 else 2
        if cs < 180:
            right(1)
            shapesize(cs)
            cs *= 1.005
        update()
    return "DONE!"

if __name__=='__main__':
    print(main())
    mainloop()