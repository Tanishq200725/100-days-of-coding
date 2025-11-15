# AI Code Detector - Usage Examples

## Real-World Scenarios

### Scenario 1: Teacher Checking Homework Assignment

**Situation**: You have 30 student submissions for a C programming assignment.

```bash
# Step 1: Organize files
mkdir assignment1
cp ~/submissions/*.c assignment1/

# Step 2: Quick batch scan
python3 ai_code_detector.py --batch assignment1/*.c

# Output:
# ======================================================================
# BATCH ANALYSIS SUMMARY
# ======================================================================
# Total files analyzed: 30
# Average AI likelihood: 25.3%
# Highest AI likelihood: 78.5%  ⚠️
# Lowest AI likelihood: 15.2%
#
# student_john.c          78.5%  HIGHLY LIKELY AI-GENERATED  🚨
# student_mary.c          22.1%  HIGHLY LIKELY HUMAN-WRITTEN
# student_bob.c           65.3%  LIKELY AI-GENERATED  ⚠️
# ...

# Step 3: Investigate high scores
python3 ai_code_detector.py assignment1/student_john.c

# Step 4: Save report for records
python3 ai_code_detector.py --output john_analysis.txt assignment1/student_john.c
```

**Action**: Interview John and Bob about their code. Check version history if available.

---

### Scenario 2: Student Self-Checking Before Submission

**Situation**: You wrote code and want to ensure it doesn't look AI-generated.

```bash
# Quick check
python3 ai_code_detector.py my_assignment.c

# Output:
# ======================================================================
# File: my_assignment.c
# AI Likelihood: 23.5%
# Verdict: HIGHLY LIKELY HUMAN-WRITTEN
# ======================================================================

# ✅ Good to submit!
```

**If score is high (>60%):**
```bash
# Get detailed breakdown
python3 ai_code_detector.py my_assignment.c

# Review which indicators are high:
# - If "Comment Quality: 90/100" → Maybe tone down perfect comments
# - If "Error Handling: 85/100" → This is actually good! Keep it.
# - If "Documentation: 95/100" → Ensure it's your own words
```

---

### Scenario 3: TA Grading Multiple Sections

**Situation**: You're grading 100+ submissions across 3 sections.

```bash
# Analyze all sections
python3 ai_code_detector.py --batch section1/*.c > section1_report.txt
python3 ai_code_detector.py --batch section2/*.c > section2_report.txt
python3 ai_code_detector.py --batch section3/*.c > section3_report.txt

# Compare sections
echo "Section 1:" && grep "Average" section1_report.txt
echo "Section 2:" && grep "Average" section2_report.txt
echo "Section 3:" && grep "Average" section3_report.txt

# Output:
# Section 1: Average AI likelihood: 24.5%
# Section 2: Average AI likelihood: 45.2%  ⚠️ (Suspicious!)
# Section 3: Average AI likelihood: 22.8%

# Get JSON for spreadsheet
python3 ai_code_detector.py --json section2/*.c > section2_data.json
```

---

### Scenario 4: Research on AI Code Patterns

**Situation**: Studying differences between human and AI code.

```bash
# Collect data
python3 ai_code_detector.py --json human_written/*.c > human_data.json
python3 ai_code_detector.py --json ai_generated/*.c > ai_data.json

# Extract percentages for analysis
grep "ai_percentage" human_data.json
grep "ai_percentage" ai_data.json

# Analyze specific indicators
python3 ai_code_detector.py ai_sample.c | grep "Comment Quality"
python3 ai_code_detector.py human_sample.c | grep "Comment Quality"
```

---

### Scenario 5: Continuous Monitoring

**Situation**: Weekly assignments throughout semester.

```bash
# Week 1
python3 ai_code_detector.py --batch week1/*.c > reports/week1.txt

# Week 2
python3 ai_code_detector.py --batch week2/*.c > reports/week2.txt

# Compare student progress
python3 ai_code_detector.py week1/student_alice.c --brief
python3 ai_code_detector.py week2/student_alice.c --brief

# If Alice's score jumps from 20% to 75%:
# Week 1: 20% (HIGHLY LIKELY HUMAN-WRITTEN)
# Week 2: 75% (HIGHLY LIKELY AI-GENERATED)  🚨
# → Investigate!
```

---

## Command Combinations

### Find All High-Risk Submissions
```bash
python3 ai_code_detector.py --batch *.c | grep -E "(LIKELY AI|HIGHLY LIKELY AI)"
```

### Sort by AI Likelihood
```bash
python3 ai_code_detector.py --batch *.c | grep "\.c" | sort -k2 -n -r
```

### Count Suspicious Files
```bash
python3 ai_code_detector.py --batch *.c | grep -c "LIKELY AI"
```

### Generate HTML Report (with conversion)
```bash
python3 ai_code_detector.py --batch *.c > report.txt
# Then convert to HTML with your preferred tool
```

---

## Integration Examples

### Shell Script for Automated Checking
```bash
#!/bin/bash
# auto_check.sh

THRESHOLD=60
OUTPUT_DIR="reports"

mkdir -p $OUTPUT_DIR

for file in submissions/*.c; do
    result=$(python3 ai_code_detector.py --json "$file")
    percentage=$(echo "$result" | grep -o '"ai_percentage": [0-9.]*' | grep -o '[0-9.]*')
    
    if (( $(echo "$percentage > $THRESHOLD" | bc -l) )); then
        echo "⚠️  HIGH SCORE: $file ($percentage%)"
        python3 ai_code_detector.py "$file" > "$OUTPUT_DIR/$(basename $file .c)_report.txt"
    fi
done
```

### Python Script for Batch Processing
```python
#!/usr/bin/env python3
import subprocess
import json
import sys

def analyze_files(files):
    results = []
    for file in files:
        cmd = ['python3', 'ai_code_detector.py', '--json', file]
        output = subprocess.check_output(cmd)
        data = json.loads(output)
        results.append(data[0])
    return results

def find_suspicious(results, threshold=60):
    return [r for r in results if r['ai_percentage'] > threshold]

if __name__ == '__main__':
    files = sys.argv[1:]
    results = analyze_files(files)
    suspicious = find_suspicious(results)
    
    print(f"Analyzed: {len(results)} files")
    print(f"Suspicious: {len(suspicious)} files")
    
    for r in suspicious:
        print(f"  {r['file']}: {r['ai_percentage']}%")
```

---

## Comparison Examples

### Human vs AI Code Side-by-Side

**Human-Written (20% AI likelihood):**
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

**AI-Generated (75% AI likelihood):**
```c
// Program to add two numbers
// This program takes two integers as input and displays their sum

#include <stdio.h>
#include <stdlib.h>

// Function to validate integer input
int getValidInteger(const char* prompt) {
    int value;
    printf("%s", prompt);
    
    if (scanf("%d", &value) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        exit(EXIT_FAILURE);
    }
    
    return value;
}

// Main function
int main() {
    int firstNumber, secondNumber, sum;
    
    // Display program header
    printf("================================\n");
    printf("Integer Addition Calculator\n");
    printf("================================\n\n");
    
    // Get input from user
    firstNumber = getValidInteger("Enter first number: ");
    secondNumber = getValidInteger("Enter second number: ");
    
    // Calculate sum
    sum = firstNumber + secondNumber;
    
    // Display result
    printf("\nResult: %d + %d = %d\n", firstNumber, secondNumber, sum);
    printf("================================\n");
    
    return EXIT_SUCCESS;
}
```

**Analysis:**
```bash
python3 ai_code_detector.py human_code.c
# AI Likelihood: 20.0% (HIGHLY LIKELY HUMAN-WRITTEN)

python3 ai_code_detector.py ai_code.c
# AI Likelihood: 75.3% (HIGHLY LIKELY AI-GENERATED)
```

---

## Troubleshooting Examples

### Problem: All scores are low
```bash
# Check if files are actually C code
file *.c

# Verify detector is working
python3 ai_code_detector.py test_ai_sample.c
# Should show ~45-50%
```

### Problem: Scores seem inconsistent
```bash
# Get detailed breakdown
python3 ai_code_detector.py --verbose suspicious_file.c

# Compare similar files
python3 ai_code_detector.py file1.c file2.c file3.c
```

### Problem: Need to adjust sensitivity
```python
# Edit ai_code_detector.py
# Modify weights dictionary:
self.weights = {
    'comment_quality': 0.20,  # Increase if comments are key indicator
    'error_handling': 0.15,   # Increase if error handling is important
    # ... adjust as needed
}
```

---

## Best Practices

### ✅ DO:
- Use batch mode for multiple files
- Save reports for documentation
- Compare scores across submissions
- Investigate high scores personally
- Use as screening tool, not final judgment

### ❌ DON'T:
- Rely solely on percentage score
- Penalize students without investigation
- Ignore context (simple programs score lower)
- Assume 100% accuracy
- Use as only verification method

---

## Quick Reference

```bash
# Single file
python3 ai_code_detector.py file.c

# Multiple files
python3 ai_code_detector.py file1.c file2.c file3.c

# All C files
python3 ai_code_detector.py *.c

# Batch summary
python3 ai_code_detector.py --batch *.c

# JSON output
python3 ai_code_detector.py --json file.c

# Brief mode
python3 ai_code_detector.py --brief file.c

# Save to file
python3 ai_code_detector.py --output report.txt file.c

# Combine options
python3 ai_code_detector.py --batch --output summary.txt *.c
```

---

For more information, see README.md or QUICKSTART.md
