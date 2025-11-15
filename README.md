# AI Code Detector for C Programming

A sophisticated tool designed to detect AI-generated code in C programming student projects. This detector analyzes multiple code patterns and characteristics to provide a percentage likelihood that code was generated using AI tools.

## Features

- **Multi-Factor Analysis**: Examines 11 different indicators of AI-generated code
- **Weighted Scoring System**: Provides accurate percentage-based detection (0-100%)
- **Detailed Reports**: Shows breakdown of each indicator with specific reasons
- **Batch Processing**: Analyze multiple files at once with summary statistics
- **Multiple Output Formats**: Text reports, JSON output, brief summaries
- **Easy to Use**: Simple command-line interface

## Detection Indicators

The detector analyzes the following aspects of C code:

1. **Comment Quality (15%)** - AI tends to have perfect, descriptive comments
2. **Formatting Consistency (12%)** - AI code has very consistent formatting
3. **Variable Naming (10%)** - AI uses descriptive, consistent naming conventions
4. **Error Handling (10%)** - AI adds comprehensive error checking
5. **Code Structure (10%)** - AI organizes code with good modularity
6. **Whitespace Perfection (8%)** - AI has perfect whitespace usage
7. **Documentation (10%)** - AI adds comprehensive documentation
8. **Complexity vs Clarity (8%)** - AI balances complexity with readability
9. **Modern Practices (7%)** - AI uses modern C standards and practices
10. **Blank Line Patterns (5%)** - AI has consistent blank line usage
11. **Comment Placement (5%)** - AI places comments strategically

## Installation

No installation required! Just ensure you have Python 3 installed:

```bash
python3 --version
```

## Usage

### Basic Usage

Analyze a single file:
```bash
python3 ai_code_detector.py code1.c
```

### Multiple Files

Analyze multiple files:
```bash
python3 ai_code_detector.py code1.c code2.c code3.c
```

Analyze all C files in directory:
```bash
python3 ai_code_detector.py *.c
```

### Batch Mode

Get summary statistics for multiple files:
```bash
python3 ai_code_detector.py --batch *.c
```

Example output:
```
======================================================================
BATCH ANALYSIS SUMMARY
======================================================================
Total files analyzed: 5
Average AI likelihood: 23.08%
Highest AI likelihood: 26.80%
Lowest AI likelihood: 20.00%

----------------------------------------------------------------------
INDIVIDUAL RESULTS:
----------------------------------------------------------------------
code1.c                         20.00%  HIGHLY LIKELY HUMAN-WRITTEN
code10.c                        26.80%  LIKELY HUMAN-WRITTEN
code50.c                        22.40%  HIGHLY LIKELY HUMAN-WRITTEN
======================================================================
```

### JSON Output

Get results in JSON format for further processing:
```bash
python3 ai_code_detector.py --json code1.c > results.json
```

### Brief Mode

Get concise output without detailed breakdown:
```bash
python3 ai_code_detector.py --brief code1.c
```

### Save to File

Save report to a file:
```bash
python3 ai_code_detector.py --output report.txt code1.c
```

## Understanding the Results

### AI Likelihood Percentage

- **0-25%**: HIGHLY LIKELY HUMAN-WRITTEN
- **25-40%**: LIKELY HUMAN-WRITTEN
- **40-60%**: POSSIBLY AI-ASSISTED
- **60-75%**: LIKELY AI-GENERATED
- **75-100%**: HIGHLY LIKELY AI-GENERATED

### Detailed Report Example

```
======================================================================
AI CODE DETECTION REPORT
======================================================================
File: test_ai_sample.c
AI Likelihood: 47.5%
Verdict: POSSIBLY AI-ASSISTED
======================================================================

DETAILED ANALYSIS:
----------------------------------------------------------------------

Comment Quality: 20/100
  • Multiple detailed inline comments

Formatting Consistency: 65/100
  • Perfect indentation pattern (step: 4)
  • Highly consistent brace placement (100.0%)

Error Handling: 75/100
  • Input validation with error messages present
  • Return value checking detected

Code Structure: 85/100
  • Code modularized with 1 helper function(s)
  • main() function at end (good structure)
  • Headers properly organized at top
  • Code organized into logical sections

...
======================================================================
```

## Command-Line Options

```
usage: ai_code_detector.py [-h] [--json] [--batch] [--brief] [--output OUTPUT] files [files ...]

AI Code Detector for C Programming - Detects AI-generated code patterns

positional arguments:
  files                 C source file(s) to analyze

optional arguments:
  -h, --help            show this help message and exit
  --json                Output results as JSON
  --batch               Batch mode with summary statistics
  --brief               Brief output (no detailed breakdown)
  --output OUTPUT, -o OUTPUT
                        Save report to file
```

## How It Works

The detector uses heuristic analysis to identify patterns commonly found in AI-generated code:

### AI-Generated Code Characteristics:
- Perfect, descriptive comments with proper grammar
- Highly consistent formatting and indentation
- Descriptive variable names (camelCase or snake_case)
- Comprehensive error handling and input validation
- Well-organized code structure with helper functions
- Perfect whitespace usage (no trailing spaces)
- Extensive documentation and inline explanations
- Strategic comment placement
- Use of modern C practices

### Human-Written Code Characteristics:
- Inconsistent or missing comments
- Variable formatting styles
- Short variable names (i, j, k, temp, etc.)
- Minimal error handling
- Less modular structure
- Inconsistent whitespace
- Minimal documentation
- Quick-and-dirty solutions

## Use Cases

### For Educators
- Check student assignments for AI usage
- Batch analyze entire class submissions
- Generate reports for academic integrity reviews

### For Students
- Verify your code doesn't accidentally look AI-generated
- Learn what makes code look professional vs student-written
- Understand code quality indicators

### For Code Reviewers
- Quick screening of code submissions
- Identify code that needs closer review
- Generate documentation for review process

## Limitations

- **Heuristic-Based**: Uses pattern matching, not machine learning
- **False Positives**: Very well-written human code may score high
- **False Negatives**: Poorly prompted AI or heavily edited AI code may score low
- **Context Matters**: Should be used as one tool among many for assessment
- **Not Definitive**: Results should inform, not replace, human judgment

## Best Practices

1. **Use as a Screening Tool**: High scores warrant closer review, not automatic penalties
2. **Consider Context**: Simple programs naturally have lower scores
3. **Combine with Other Methods**: Interview students, check version history, etc.
4. **Batch Analysis**: Compare scores across multiple submissions
5. **Document Results**: Save reports for record-keeping

## Examples

### Example 1: Simple Human Code
```c
#include<stdio.h>
int main() {
    int a,b,c;
    scanf("%d", &a);
    scanf("%d", &b);
    c = a + b;
    printf("%d", c);
    return 0;
}
```
**Result**: ~20% (HIGHLY LIKELY HUMAN-WRITTEN)

### Example 2: AI-Style Code
```c
// Program to calculate factorial using recursion
#include <stdio.h>

// Function to calculate factorial recursively
long long calculateFactorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n <= 1) {
        return 1;
    }
    // Recursive case
    return n * calculateFactorial(n - 1);
}

int main() {
    int number;
    
    printf("Enter a positive integer: ");
    if (scanf("%d", &number) != 1) {
        fprintf(stderr, "Error: Invalid input.\n");
        return 1;
    }
    
    printf("Factorial = %lld\n", calculateFactorial(number));
    return 0;
}
```
**Result**: ~45-60% (POSSIBLY AI-ASSISTED to LIKELY AI-GENERATED)

## Technical Details

- **Language**: Python 3
- **Dependencies**: None (uses only standard library)
- **Performance**: Analyzes ~100 files/second on typical hardware
- **File Support**: .c files only

## Contributing

To improve detection accuracy:
1. Analyze false positives/negatives
2. Adjust weights in the `weights` dictionary
3. Add new detection indicators
4. Test on diverse code samples

## License

Free to use for educational purposes.

## Support

For issues or questions, review the code comments or modify detection parameters to suit your needs.

---

**Note**: This tool is designed to assist in detecting AI-generated code, but should not be the sole basis for academic integrity decisions. Always combine automated detection with human judgment and additional verification methods.
