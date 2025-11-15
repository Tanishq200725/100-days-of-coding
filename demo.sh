#!/bin/bash

# AI Code Detector - Demo Script
# This script demonstrates the capabilities of the AI code detector

echo "=========================================="
echo "AI CODE DETECTOR - DEMONSTRATION"
echo "=========================================="
echo ""

echo "📝 Demo 1: Analyzing a single file"
echo "Command: python3 ai_code_detector.py code1.c"
echo "------------------------------------------"
python3 ai_code_detector.py code1.c
echo ""
echo "Press Enter to continue..."
read

echo ""
echo "📊 Demo 2: Batch analysis of multiple files"
echo "Command: python3 ai_code_detector.py --batch code1.c code10.c code50.c"
echo "------------------------------------------"
python3 ai_code_detector.py --batch code1.c code10.c code50.c
echo ""
echo "Press Enter to continue..."
read

echo ""
echo "🤖 Demo 3: Analyzing AI-style code"
echo "Command: python3 ai_code_detector.py test_ai_sample.c"
echo "------------------------------------------"
python3 ai_code_detector.py test_ai_sample.c
echo ""
echo "Press Enter to continue..."
read

echo ""
echo "📋 Demo 4: Brief output mode"
echo "Command: python3 ai_code_detector.py --brief test_ai_sample.c"
echo "------------------------------------------"
python3 ai_code_detector.py --brief test_ai_sample.c
echo ""
echo "Press Enter to continue..."
read

echo ""
echo "💾 Demo 5: Saving report to file"
echo "Command: python3 ai_code_detector.py --output demo_report.txt code1.c"
echo "------------------------------------------"
python3 ai_code_detector.py --output demo_report.txt code1.c
echo ""
echo "Report saved! Contents:"
cat demo_report.txt
echo ""
echo "Press Enter to continue..."
read

echo ""
echo "🔢 Demo 6: JSON output"
echo "Command: python3 ai_code_detector.py --json code1.c"
echo "------------------------------------------"
python3 ai_code_detector.py --json code1.c | head -40
echo "... (truncated)"
echo ""

echo ""
echo "=========================================="
echo "✅ DEMONSTRATION COMPLETE"
echo "=========================================="
echo ""
echo "Key Takeaways:"
echo "  • Human-written code typically scores 15-35%"
echo "  • AI-generated code typically scores 50-80%"
echo "  • Use --batch for analyzing multiple files"
echo "  • Use --json for programmatic processing"
echo "  • Always combine with human judgment"
echo ""
echo "For more information, see README.md or QUICKSTART.md"
