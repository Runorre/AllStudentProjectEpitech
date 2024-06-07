#!/usr/bin/env python3
##
## EPITECH PROJECT, 2022
## 104intersection
## File description:
## Maths
##
import math
import sys

def sphere_intersection(x0, y0, z0, vx, vy, vz, r):
    a = vx**2 + vy**2 + vz**2
    b = 2 * (x0*vx + y0*vy + z0*vz)
    c = x0**2 + y0**2 + z0**2 - r**2
    if math.sqrt(x0**2 + y0**2 + z0**2) <= r:
        return ("There is an infinite number of intersection points.")
    if (a == 0):
        return ("There is an infinite number of intersection points.")
    discriminant = b**2 - 4*a*c
    if discriminant < 0:
        return []
    elif discriminant == 0:
        t = -b / (2*a)
        if math.sqrt(x0**2 + y0**2 + z0**2) < r:
            exit (84)
        return [(x0 + t*vx, y0 + t*vy, z0 + t*vz)]
    else:
        t1 = (-b + math.sqrt(discriminant)) / (2*a)
        t2 = (-b - math.sqrt(discriminant)) / (2*a)
        return [(x0 + t1*vx, y0 + t1*vy, z0 + t1*vz), (x0 + t2*vx, y0 + t2*vy, z0 + t2*vz)]

def cylinder_intersection(x0, y0, z0, vx, vy, vz, r):
    a = vx**2 + vy**2
    b = 2 * (x0*vx + y0*vy)
    c = x0**2 + y0**2 - r**2
    if abs(z0) <= r:
        return ("There is an infinite number of intersection points.")
    if (a == 0):
        return ("There is an infinite number of intersection points.")
    discriminant = b**2 - 4*a*c
    if discriminant < 0:
        return []
    elif discriminant == 0:
        t = -b / (2*a)
        if abs(z0) < r:
            exit(84)
        return [(x0 + t*vx, y0 + t*vy, z0 + t*vz)]
    else:
        t1 = (-b + math.sqrt(discriminant)) / (2*a)
        t2 = (-b - math.sqrt(discriminant)) / (2*a)
        return [(x0 + t1*vx, y0 + t1*vy, z0 + t1*vz), (x0 + t2*vx, y0 + t2*vy, z0 + t2*vz)]

def cone_intersection(x0, y0, z0, vx, vy, vz, theta):
    theta = theta*math.pi/180

    a = vx**2 + vy**2 - vz**2*math.tan(theta)**2
    b = 2*(vx*x0 + vy*y0 - vz*z0*math.tan(theta)**2)
    c = x0**2 + y0**2 - z0**2*math.tan(theta)**2
    if (a == 0):
        return ("There is an infinite number of intersection points.")
    discriminant = b**2 - 4*a*c
    if discriminant < 0:
        return []
    elif discriminant == 0:
        t = -b / (2*a)
        return [(x0 + t*vx, y0 + t*vy, z0 + t*vz)]
    else:
        t1 = (-b + math.sqrt(discriminant)) / (2*a)
        t2 = (-b - math.sqrt(discriminant)) / (2*a)
        return [(x0 + t1*vx, y0 + t1*vy, z0 + t1*vz), (x0 + t2*vx, y0 + t2*vy, z0 + t2*vz)]

def num_rows(matrix):
    return len(matrix)

def num_columns(matrix):
    return len(matrix[0])

def number_inter(matrix):
    if (num_rows(matrix) == 0):
        return 0
    if (num_rows(matrix) == 1):
        return (1)
    elif (num_rows(matrix) == 2):
        return (2)

def print_list(res):
    if (res == "There is an infinite number of intersection points."):
        print("There is an infinite number of intersection points.")
        exit(0)
    if (number_inter(res) == 0):
        print("No intersection point.")
    elif (number_inter(res) == 1):
        print("1 intersection point:")
        print("(%.3f," % res[0][0], "%.3f," % res[0][1], "%.3f)" % res[0][2])
    else:
        print("2 intersection points:")
        print("({}, {}, {})\n({}, {}, {})".format("%.3f" % res[0][0], "%.3f" % res[0][1], "%.3f" % res[0][2], "%.3f" % res[1][0], "%.3f" % res[1][1], "%.3f" % res[1][2]))
    exit(0)

def main():
    #1 sphere, 2 cylindre, 3 cone
    try:
        opt = int(sys.argv[1])
        xp = int(sys.argv[2])
        yp = int(sys.argv[3])
        zp = int(sys.argv[4])
        xv = int(sys.argv[5])
        yv = int(sys.argv[6])
        zv = int(sys.argv[7])
        p = int(sys.argv[8])
    except:
        print("Please, input 8 arguments")
        exit(84)
    if len(sys.argv) != 9:
        exit(84)
    if (opt == 1):
        if (p <= 0):
            exit(84)
        string = "Sphere"
    elif (opt == 2):
        string = "Cylinder"
    elif (opt == 3):
        string = "Cone"
    else:
        exit(84)
    if (opt != 3):
        print("{} of radius {}".format(string, p))
    else:
        print("{} with a {} degree angle".format(string, p))
    print("Line passing through the point ({}, {}, {}) and parallel to the vector ({}, {}, {})".format(xp, yp, zp, xv, yv, zv))
    if (opt == 1):
        res = sphere_intersection(xp, yp, zp, xv, yv, zv, p)
        print_list(res)
    elif (opt == 2):
        res = cylinder_intersection(xp, yp, zp, xv, yv, zv, p)
        print_list(res)
    elif (opt == 3):
        res = cone_intersection(xp, yp, zp, xv, yv, zv, p)
        print_list(res)
    else:
        exit(84)
    return 0


if __name__ == "__main__":
    main()
