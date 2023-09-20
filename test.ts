// Function to convert a hexadecimal string to a regular string
function hexadecimalToString(hexString: string): string | null {
    const len = hexString.length;

    // Check if the input string has an even length
    if (len % 2 !== 0) {
        return null; // Invalid hexadecimal string
    }

    const stringArray: string[] = [];

    for (let i = 0; i < len; i += 2) {
        const hexPair = hexString.slice(i, i + 2);

        // Convert the hexadecimal pair back to a character
        const charCode = parseInt(hexPair, 16);
        if (isNaN(charCode)) {
            return null; // Invalid hexadecimal character
        }

        stringArray.push(String.fromCharCode(charCode));
    }

    return stringArray.join('');
}

const hexInput = "48656C6C6F2C20776F726C6421"; // Hexadecimal representation of "Hello, world!"
const outputString = hexadecimalToString(hexInput);

if (outputString !== null) {
	console.log(hexInput);
    console.log(outputString);
} else {
    console.log("Invalid hexadecimal input.");
}

function hexStringToShort(hexString: string): number | null {
  // Parse the hexadecimal string to an integer
  const intValue = parseInt(hexString, 16);

  // Check if the parsed value is within the range of a short integer
  if (intValue >= -32768 && intValue <= 32767) {
    return intValue;
  } else {
    // Return null if the value is out of range
    return null;
  }
}

// Example usage:
const hexValue = "7FFF"; // Replace with your hexadecimal string
const shortInt = hexStringToShort(hexValue);

if (shortInt !== null) {
  console.log(`Hexadecimal ${hexValue} is equivalent to short integer ${shortInt}`);
} else {
  console.log(`Hexadecimal ${hexValue} is out of the valid range for a short integer.`);
}
