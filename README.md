# Image-to-ascii-art
font-family: monospace;

This program uses the STB library to convert an image to ASCII art
After compiling main.c and running it, the program will ask for a file name. The file has to be an image in the same directory as the program
The program will then ask for the desired width for the ASCII art that it will output, and the height will be based on the ratio of the original image

After resizing the image, an array of strings is created where each char represents a pixel. The program looks at each pixel and averages the rgb values to get it's brightness. The brightness is mapped to a density char from this string: "_.=+:;!?c71236089$W#@" and that density char goes to the corrosponding spot in the array of strings. The program outputs the resulting array of strings.

For example, using the dog.jpg image and a width of 64 takes this image:<br/>
![dog](dog.jpg)<br/>

And outputs this:<br/>
```
0000066606666606060666066333322222223333366666666666666666660000
0666666666666663333633322333323321222363322221771133666666666666
000000000066631777c1111236633222212223336321c!;!!?72366666666660
6666666663221cc?!;:!c2366333333322233321c72337:=:;!c711233333333
3333333327ccc!!:+=:?227c??713663322332c;.=+:c27;++:!ccc?72366666
33333327?!;;:::+++;c1;:+::!7222117777117ccccc7c?!=:;!??!!?726660
3336337:;:++:::++:;!7777121117c?!;;;;!c1233222c!;+:;!!!;:::c2366
636327!+====+:::+=:!711222717!:+====..+!1233227!:+::!;:+++:!c136
6632c!:=====+::::+:!71222112c+=.......=+c222227?:=+:;;:+==:;!?13
631c!:+=====+:::++:!c71211117!+=......=:?122327?:=+::::+=++::;c3
37!;:+===...=:::+++;!c7111217!:=......=:?72211c:++::++====++:?36
67::+========+::++++:!777117c!:=.......+;c17?1!===+++==+==+?1366
6637;=..====+::+===++!1??ccc!+=..____..=+;!:?1;==++===++;c266666
666662c;=.=+:;:===+++;7c;=+::+=.....===++._!7c:==+++==+;26666666
6666666627?::;++===++:?cc+_=;!;::++::;;!:.:17;++=+++:!7266666666
666666666631c;::+===++:?1c=.;?!!!!!!!!?c;=?2!:+=++::!13666666666
6666666666663c;::====+:;c1!+???!!!!!???!+!7c+==+::;;133336666666
06666666666662?;:+:::;;!!?c;;!!!!!!!;;:;!cc+==++:;;!366666666666
666666666663661!::;;;;;;;;;;!!;!;;;;;!???!;;:++::!72666666666666
666666666666663c;;;;!:::;:+==+++:;:;!!;:++::::::;?26666666666666
666666666666637c?!!;!;:::+===...====+++++++:;;;;!!?1366666666666
6666666666663c!!;!!;;;;:;:+++=====+=++:++::;;::;;;!?736666666666
```