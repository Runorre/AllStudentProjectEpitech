##
## EPITECH PROJECT, 2024
## B-OOP-400-MAR-4-1-raytracer-angelo.anselmet
## File description:
## generator
##

import sys
from typing import Literal

class Data():
    def __init__(self, hasCamera: bool) -> None:
        self.hasCamera: bool = hasCamera
        self.spheres: list[Sphere] = []
        self.planes: list[Plane] = []
        self.lights: list[Light] = []
        self.camera: Camera = None

class Camera():
    def __init__(self, height : int, width : int, x: float, y: float, z: float, vx: float, vy: float, vz: float, fov: float) -> None:
        self.height: int = height
        self.width : int = width
        self.position: list[float] = [x, y, z]
        self.rotation: list[float] = [vx, vy, vz]
        self.fov: float = fov

class Sphere():
    def __init__(self, x: float, y: float, z: float, radius: float, red: int, green: int, blue: int) -> None:
        self.position: list[float] = [x, y, z]
        self.radius: float = radius
        self.color: list[int] = [red, green, blue]

class Plane():
    def __init__(self, axis : str, position : float, red : int, green : int, blue : int) -> None:
        self.axis : str = axis
        self.position : float = position
        self.color : list[int] = [red, green, blue]

class Light():
    def __init__(self, ambient : float, diffuse : float, red : int, green : int, blue : int) -> None:
        self.ambient : float = ambient
        self.diffuse : float = diffuse
        self.color : list[int] = [red, green, blue]

def getInput(entity : bool) -> str:
    try:
        if entity:
            line: str = input("\nInput: ")
        else:
            line: str = input("Please select a name for your file: ")
    except EOFError:
        raise Exception("Exiting program...")
    except KeyboardInterrupt:
        raise Exception("Exiting program...")
    except ValueError:
        return "Invalid"
    if line == "END":
        return "END"
    if line == "":
        exit(84)
    return line

def showData(UserData : Data) -> None:
    camText : str = "Camera: "
    if not UserData.hasCamera:
        camText += "No camera found"
    print("Spheres:")
    for sphere in UserData.spheres:
        print("Sphere:")
        print("Position: ", sphere.position)
        print("Radius: ", sphere.radius)
        print("Color: ", sphere.color)
    print("Planes:")
    for plane in UserData.planes:
        print("Plane:")
        print("Axis: ", plane.axis)
        print("Position: ", plane.position)
        print("Color: ", plane.color)
    print("Lights:")
    for light in UserData.lights:
        print("Light:")
        print("Ambient: ", light.ambient)
        print("Diffuse: ", light.diffuse)
        print("Color: ", light.color)

def lineSwitch(line : str, UserData : Data) -> Data:
    print(line)
    if line == "end" and UserData.hasCamera:
        return UserData
    elif line == "end" and not UserData.hasCamera:
        print("No camera found, please create one\n")
    elif line == "Sphere":
        UserData.spheres.append(createSphere())
    elif line == "plane":
        UserData.planes.append(createPlane())
    elif line == "light":
        UserData.lights.append(createLight())
    elif line == "camera":
        if UserData.hasCamera:
            print("Camera already exists")
            choiceLoop : bool = True
            deleteLoop : bool = True
            while (deleteLoop):
                line = getInput("Do you wish to delete it ? (y/n)")
                if line == "y":
                    UserData.hasCamera = False
                    UserData.camera = None
                    deleteLoop = False
                elif line == "n":
                    deleteLoop = False
            while (choiceLoop):
                line = getInput("Do you wish to change it ? (y/n)")
                if line == "y":
                    print("ok")
                elif line == "n":
                    return UserData
        else:
            camera : Camera = createCamera()
            UserData.camera = camera
            UserData.hasCamera = True
    elif line == "show":
        showData(UserData)
    elif line == "help":
        printHelp()
    else:
        print("Invalid input, please try again...")
    return UserData

def getValue(type : str, message : str) -> int | float | str:
    try:
        if type == "int":
            value : float = int(input(message))
        elif type == "float":
            value : float = float(input(message))
        elif type == "str":
            value: str = input(message)
    except ValueError:
        return "Invalid"
    except EOFError:
        raise Exception("Exiting program...")
    except KeyboardInterrupt:
        raise Exception("Exiting program...")
    except Exception:
        raise Exception("Exiting program...")
    return value

def createLight() -> Light:
    print("Creating light...")
    ambient : float = float(getValue("float", "Ambient (Float): "))
    diffuse : float = float(getValue("float", "Diffuse (Float): "))
    red : int = int(getValue("int", "Red (Integer): "))
    green : int = int(getValue("int", "Green (Integer): "))
    blue : int = int(getValue("int", "Blue (Integer): "))
    if ambient == "Invalid" or diffuse == "Invalid" or red == "Invalid" or green == "Invalid" or blue == "Invalid":
        print("Invalid input, please try again...")
        return createLight()
    else:
        print("\nLight created !\n")
        light : Light = Light(ambient, diffuse, red, green, blue)
        return light

def createPlane() -> Plane:
    print("Creating plane...")
    axis : str = getValue("str", "Axis (String): ")
    position : float = float(getValue("float", "Position (Float): "))
    red : int = int(getValue("int", "Red (Integer): "))
    green : int = int(getValue("int", "Green (Integer): "))
    blue : int = int(getValue("int", "Blue (Integer): "))
    if axis == "Invalid" or position == "Invalid" or red == "Invalid" or green == "Invalid" or blue == "Invalid":
        print("Invalid input, please try again...")
        return createPlane()
    else:
        print("\nPlane created !\n")
        plane : Plane = Plane(axis, position, red, green, blue)
        return plane

def createSphere() -> Sphere:
    print("Creating sphere...")
    x : float = float(getValue("float", "X (Float): "))
    y : float = float(getValue("float", "Y (Float): "))
    z : float = float(getValue("float", "Z (Float): "))
    radius : float = float(getValue("float", "Radius (Float): "))
    red : int = int(getValue("float", "Red (Integer): "))
    green : int = int(getValue("float", "Green (Integer): "))
    blue : int = int(getValue("float", "Blue (Integer): "))
    if x == "Invalid" or y == "Invalid" or z == "Invalid" or radius == "Invalid" or red == "Invalid" or green == "Invalid" or blue == "Invalid":
        print("Invalid input, please try again...")
        return createSphere()
    else:
        print("\nSphere created !\n")
        sphere : Sphere = Sphere(x, y, z, radius, red, green, blue)
        return sphere

def createCamera() -> Camera:
    print("Creating camera...")
    height : int = int(getValue("int", "Height (Integer): "))
    width : int = int(getValue("int", "Width (Integer): "))
    x : float = float(getValue("float", "X (Float): "))
    y : float = float(getValue("float", "Y (Float): "))
    z : float = float(getValue("float", "Z (Float): "))
    vx : float = float(getValue("float", "VX (Float): "))
    vy : float = float(getValue("float", "VY (Float): "))
    vz : float = float(getValue("float", "VZ (Float): "))
    fov : float = float(getValue("float", "FOV (Float): "))
    if height == "Invalid" or width == "Invalid" or x == "Invalid" or y == "Invalid" or z == "Invalid" or vx == "Invalid" or vy == "Invalid" or vz == "Invalid" or fov == "Invalid":
        print("Invalid input, please try again...")
        return createCamera()
    else: 
        print("\nCamera created !\n")
        return Camera(height, width, x, y, z, vx, vy, vz, fov)

def printCamera(UserData : Data, file) -> None:
    print("Printing camera...")
    file.write("Camera : {\n")
    file.write("\tresolution : { width = " + str(UserData.camera.width) + ", height = " + str(UserData.camera.height) + " };\n")
    file.write("\tposition = { x = " + str(UserData.camera.position[0]) + ", y = " + str(UserData.camera.position[1]) + ", z = " + str(UserData.camera.position[2]) + " };\n")
    file.write("\trotation = { x = " + str(UserData.camera.rotation[0]) + ", y = " + str(UserData.camera.rotation[1]) + ", z = " + str(UserData.camera.rotation[2]) + " };\n")
    file.write("\tfieldOfView = " + str(UserData.camera.fov) + ";\n")
    file.write("};\n")

def printPrimitives(UserData : Data, file) -> None:
    print("Printing primitives...")
    file.write("Primitives : {\n")
    if len(UserData.spheres) > 0:
        file.write("\tspheres: {\n")
        for sphere in UserData.spheres:
            file.write("\t\t{ x = " + str(sphere.position[0]) + ", y = " + str(sphere.position[1]) + ", z = " + str(sphere.position[2]) + ", r = " + str(sphere.radius) + ", color = { r = " + str(sphere.color[0]) + ", g = " + str(sphere.color[1]) + ", b = " + str(sphere.color[2]) + " } }\n")
        file.write("\t};\n")
    if len(UserData.planes) > 0:
        file.write("\tplanes: {\n")
        for plane in UserData.planes:
            file.write("\t\t{ axis = " + plane.axis + ", position = " + str(plane.position) + ", color = { r = " + str(plane.color[0]) + ", g = " + str(plane.color[1]) + ", b = " + str(plane.color[2]) + " } }\n")
        file.write("\t};\n")
    file.write("};\n\n")

def printInFile(UserData : Data, fileName : str) -> None:
    print("\nPrinting in file...")
    file = open("config/"+fileName, "w")
    printCamera(UserData, file)
    if len(UserData.spheres) > 0 or len(UserData.planes) > 0:
        printPrimitives(UserData, file)
    file.close()
    print("File created !")

def generator() -> None:
    UserData : Data = Data(False)
    runningLoop : bool = True
    print("Welcome to the Raytracer config file generator !\n")
    fileName : str = getInput(False)
    while (runningLoop):
        line: str = getInput(True)
        UserData = lineSwitch(line, UserData)
        if line == "END":
            runningLoop = False
    printInFile(UserData, fileName)

def printHelp() -> None:
    print("\nInputs avaiable (Uppercases/lowercases doesn't matter):\n- Camera\n- Sphere\n- Plane\n- Help\n- Data\n- Light\n- END")

def printCorrectUsage() -> str:
    return "USAGE\n./generator\n\nDESCRIPTION\nConfig file generator for Raytracer project !"

def main() -> Literal[84] | Literal[0]:
    try:
        if len(sys.argv) != 1:
            raise Exception(printCorrectUsage())
        generator()
    except Exception as e:
        print(e)
        return 0

if __name__ == "__main__":
    sys.exit(main())
