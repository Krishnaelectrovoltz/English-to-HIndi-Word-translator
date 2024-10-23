 # English to Hindi Word Translator

This is a simple English to Hindi word translator program implemented in C language using web scraping. The program allows you to enter an English word and it will fetch the corresponding Hindi translation from a specified website.

## Prerequisites 

To run this program, you need to have the following software installed on your system: 

- C compiler (e.g., GCC)

## Setup

1. Clone or download the repository containing the source code.

2. Open a terminal or command prompt and navigate to the project directory.

3. Compile the C program using the following command:

   ```
   gcc translator.c -o translator
   ```

4. Run the compiled program:

   ```
   ./translator
   ```

## Usage

1. Upon running the program, you will be prompted to enter an English word.

2. Enter the word and press Enter.

3. The program will scrape the website to find the corresponding Hindi translation of the entered word.

4. The Hindi translation will be displayed on the console.

5. You can repeat the process by entering another word or exit the program by entering "exit" or pressing Ctrl+C.

## Implementation Details

The translator program utilizes web scraping to fetch the Hindi translation from a specified website. The implementation uses the following steps:

1. The program takes user input for an English word.

2. It constructs a URL with the entered word and sends an HTTP request to the website.

3. The program parses the HTML response received from the website.

4. It extracts the Hindi translation of the word from the parsed HTML.

5. Finally, the program displays the translated word on the console.

## Limitations

- This translator program relies on web scraping, which means it is dependent on the structure and layout of the website being scraped. Any changes to the website's structure may cause the program to break.

- The program may not be able to handle certain edge cases or words with multiple translations.

## Resources

- [GCC - The GNU Compiler Collection](https://gcc.gnu.org/)
- [C Programming Language](https://en.wikipedia.org/wiki/C_(programming_language))

## License

This project is licensed under the [MIT License](LICENSE). Feel free to modify and distribute it according to the terms of the license.

## Disclaimer

This program is provided as-is and with no warranty. The authors are not responsible for any damage or loss of data caused by the use of this program. Use it at your own risk.

---

Note: This README file provides an overview of the English to Hindi word translator program implemented using web scraping in C language. For detailed source code and implementation, please refer to the provided source code file.
