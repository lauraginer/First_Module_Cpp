# Test 1: Básico
echo "hello world hello" > test1.txt
./replace test1.txt hello bye
cat test1.txt.replace  # Debe mostrar: "bye world bye"
echo ""

# Test 2: Sin ocurrencias
echo "foo bar" > test2.txt
./replace test2.txt hello bye
cat test2.txt.replace  # Debe mostrar: "foo bar"
echo ""

# Test 3: Múltiples líneas
echo "hello\nhello world\nhello" > test3.txt
./replace test3.txt hello bye
cat test3.txt.replace
echo ""

# Test 4: s1 más largo que s2
echo "hello world hello" > test4.txt
./replace test4.txt hello hi
cat test4.txt.replace
echo ""

# Test 5: s2 más largo que s1
echo "hello world hello" > test5.txt
./replace test5.txt hi hello
cat test5.txt.replace
echo ""

# Test 6: Archivo no existe
./replace noexiste.txt a b  # Error
echo ""

# Test 7: Argumentos vacíos
./replace "" a b  # Error
echo ""

./replace test.txt "" b  # Error
echo ""