// Convert to Fahrenheit
function convertToFahrenheit(celsius){
    let fahrenheit = (celsius*9/5)+32;
    return String(fahrenheit)+'F';
}
// console.log(convertToFahrenheit(25));

// Convert to Celsius
function convertToCelsius(fahrenheit){
    let celsius = (fahrenheit-32)*5/9;
    return String(celsius)+ 'C';
}
// console.log(convertToCelsius(86));

// Convert Temperature
function convertTemperature(degrees,unit){
    if(unit==='C'){
        let ans = convertToFahrenheit(degrees);
        console.log(ans);
    }
    else if(unit==='F'){
        let ans = convertToCelsius(degrees);
        console.log(ans);
    }
    else{
        console.log("Not a valid scale for measuring temperature");
    }
}
convertTemperature(25,'C');
convertTemperature(86,'F');
convertTemperature(86,'K');