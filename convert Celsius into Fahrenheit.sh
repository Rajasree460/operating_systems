#convert Celsius into Fahrenheit
echo "Enter temperature in Celsius: "
read celsius
 
# formula to convert Celsius to Fahrenheit: F = (C * 9/5) + 32
fahrenheit=$(echo "scale=2;($celsius * 9/5) + 32" | bc)
 
echo "${celsius}°C is equal to ${fahrenheit}°F"
