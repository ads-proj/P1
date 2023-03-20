### ADS small searching engine

​	Due to the use of \<filesystem\>, the project **must be constructed under C++17**

​	We strongly recommend you to construct this project by CMake. After you ensure the environment of C++17 is enable. The following code is used to build this project.

```shell
mkdir build
cd build
cmake ..
```

​	After executing the code above, you may discover three executable file named "P1_dict", "query", "stop".

​	The first one is used to build the inverted file index, it will created a directory "dict" automatically and load in the index, so It should be runned first.

​	Then you can run the "query" to search for key words inside the  Shakespeare's books.

​	The program stop is used to find out the top 100 most frequently occurring words, which we consider to be stop words.

​	The "sample" directory stores the original text of Shakespeare's works, The "dict" directory stores dict.txt, which is the inverted file index created by our program.