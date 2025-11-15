# Quick Start Guide - AI Code Detector

## 🚀 Get Started in 30 Seconds

### 1. Check Single File
```bash
python3 ai_code_detector.py code1.c
```

### 2. Check All Student Submissions
```bash
python3 ai_code_detector.py --batch *.c
```

### 3. Save Report
```bash
python3 ai_code_detector.py --batch --output class_report.txt *.c
```

## 📊 Understanding Scores

| Score Range | Verdict | Action |
|-------------|---------|--------|
| 0-25% | HIGHLY LIKELY HUMAN | ✅ Probably fine |
| 25-40% | LIKELY HUMAN | ✅ Acceptable |
| 40-60% | POSSIBLY AI-ASSISTED | ⚠️ Review recommended |
| 60-75% | LIKELY AI-GENERATED | ⚠️ Closer inspection needed |
| 75-100% | HIGHLY LIKELY AI | 🚨 Strong AI indicators |

## 🎯 Common Use Cases

### For Teachers - Check Homework
```bash
# Analyze all submissions
python3 ai_code_detector.py --batch student_submissions/*.c

# Save detailed report
python3 ai_code_detector.py --output homework1_report.txt student_submissions/*.c
```

### For Students - Self-Check
```bash
# Check your code before submission
python3 ai_code_detector.py my_assignment.c

# Brief check
python3 ai_code_detector.py --brief my_assignment.c
```

### For TAs - Batch Grading
```bash
# Get JSON for spreadsheet import
python3 ai_code_detector.py --json --batch *.c > results.json

# Quick summary
python3 ai_code_detector.py --batch --brief *.c
```

## 🔍 What Gets Detected?

### High AI Likelihood Indicators:
- ✓ Perfect comments with proper grammar
- ✓ Comprehensive error handling
- ✓ Descriptive variable names (calculateFactorial, totalSeconds)
- ✓ Well-organized code structure
- ✓ Consistent formatting throughout
- ✓ Extensive documentation

### Low AI Likelihood Indicators:
- ✓ Minimal or no comments
- ✓ Short variable names (a, b, c, temp)
- ✓ Inconsistent formatting
- ✓ No error handling
- ✓ Simple, straightforward code
- ✓ Trailing whitespace and formatting quirks

## 💡 Pro Tips

1. **Batch Mode is Your Friend**: Use `--batch` to quickly scan entire classes
2. **Save Reports**: Use `--output` to keep records for academic integrity
3. **Compare Scores**: Look for outliers - one 80% in a class of 20%s is suspicious
4. **Context Matters**: Simple "Hello World" programs will naturally score low
5. **Not Definitive**: Use as a screening tool, not final judgment

## 🎓 Example Workflow for Educators

```bash
# Step 1: Collect all submissions in one folder
mkdir assignment1_submissions
cp /path/to/student/files/*.c assignment1_submissions/

# Step 2: Run batch analysis
python3 ai_code_detector.py --batch assignment1_submissions/*.c > summary.txt

# Step 3: Review high-scoring submissions
python3 ai_code_detector.py assignment1_submissions/suspicious_file.c

# Step 4: Save detailed reports for records
python3 ai_code_detector.py --output detailed_report.txt assignment1_submissions/*.c
```

## ⚙️ All Options

```bash
python3 ai_code_detector.py [OPTIONS] file1.c file2.c ...

Options:
  --batch       Show summary statistics
  --json        Output as JSON
  --brief       Concise output
  --output FILE Save to file
  -h, --help    Show help
```

## 📝 Sample Output

### Single File Analysis:
```
======================================================================
AI CODE DETECTION REPORT
======================================================================
File: code1.c
AI Likelihood: 20.0%
Verdict: HIGHLY LIKELY HUMAN-WRITTEN
======================================================================
```

### Batch Analysis:
```
======================================================================
BATCH ANALYSIS SUMMARY
======================================================================
Total files analyzed: 25
Average AI likelihood: 28.5%
Highest AI likelihood: 72.3%
Lowest AI likelihood: 18.2%

----------------------------------------------------------------------
INDIVIDUAL RESULTS:
----------------------------------------------------------------------
code1.c                         20.0%   HIGHLY LIKELY HUMAN-WRITTEN
code2.c                         23.5%   HIGHLY LIKELY HUMAN-WRITTEN
code3.c                         72.3%   LIKELY AI-GENERATED  ⚠️
...
======================================================================
```

## ❓ FAQ

**Q: Can this definitively prove AI usage?**
A: No. It's a screening tool. High scores warrant further investigation.

**Q: What if a good student scores high?**
A: Excellent human code can score high. Use other verification methods (interviews, version history).

**Q: Can students game this?**
A: Intentionally making code messy to lower scores defeats the purpose of learning.

**Q: How accurate is it?**
A: It's heuristic-based, not ML. Best used for screening, not final decisions.

## 🚨 Important Notes

- **Not a Lie Detector**: Use as one tool among many
- **Context is Key**: Simple programs naturally score lower
- **Human Judgment Required**: Always investigate high scores personally
- **Educational Tool**: Help students understand code quality indicators

---

**Ready to start?** Just run:
```bash
python3 ai_code_detector.py your_file.c
```
