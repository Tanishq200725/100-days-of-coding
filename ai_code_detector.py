#!/usr/bin/env python3
"""
AI Code Detector for C Programming
Analyzes C code to detect likelihood of AI generation
"""

import re
import os
import sys
import json
import argparse
from pathlib import Path
from typing import Dict, List, Tuple
from collections import Counter


class CCodeAIDetector:
    """Detects AI-generated patterns in C code"""
    
    def __init__(self):
        self.indicators = {}
        self.weights = {
            'comment_quality': 0.15,
            'formatting_consistency': 0.12,
            'variable_naming': 0.10,
            'error_handling': 0.10,
            'code_structure': 0.10,
            'whitespace_perfection': 0.08,
            'documentation': 0.10,
            'complexity_clarity': 0.08,
            'modern_practices': 0.07,
            'blank_line_patterns': 0.05,
            'comment_placement': 0.05
        }
    
    def analyze_file(self, filepath: str) -> Dict:
        """Analyze a C file and return detection results"""
        try:
            with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
                code = f.read()
        except Exception as e:
            return {'error': f"Failed to read file: {str(e)}"}
        
        # Run all detection indicators
        self.indicators = {
            'comment_quality': self._check_comment_quality(code),
            'formatting_consistency': self._check_formatting_consistency(code),
            'variable_naming': self._check_variable_naming(code),
            'error_handling': self._check_error_handling(code),
            'code_structure': self._check_code_structure(code),
            'whitespace_perfection': self._check_whitespace_perfection(code),
            'documentation': self._check_documentation(code),
            'complexity_clarity': self._check_complexity_clarity(code),
            'modern_practices': self._check_modern_practices(code),
            'blank_line_patterns': self._check_blank_line_patterns(code),
            'comment_placement': self._check_comment_placement(code)
        }
        
        # Calculate weighted score
        ai_percentage = self._calculate_score()
        
        return {
            'file': filepath,
            'ai_percentage': round(ai_percentage, 2),
            'indicators': self.indicators,
            'verdict': self._get_verdict(ai_percentage)
        }
    
    def _check_comment_quality(self, code: str) -> Dict:
        """AI tends to have perfect, descriptive comments"""
        score = 0
        reasons = []
        
        comments = re.findall(r'//.*?$|/\*.*?\*/', code, re.MULTILINE | re.DOTALL)
        
        if not comments:
            reasons.append("No comments found (typical of rushed human code)")
            return {'score': 20, 'reasons': reasons}
        
        # Check for overly descriptive comments
        descriptive_patterns = [
            r'(calculate|compute|determine|process|handle|manage)',
            r'(initialize|declare|define)',
            r'(iterate|loop through)',
            r'(check|verify|validate)',
            r'(store|save|update)'
        ]
        
        descriptive_count = 0
        for comment in comments:
            for pattern in descriptive_patterns:
                if re.search(pattern, comment, re.IGNORECASE):
                    descriptive_count += 1
                    break
        
        if len(comments) > 0:
            descriptive_ratio = descriptive_count / len(comments)
            if descriptive_ratio > 0.6:
                score += 40
                reasons.append(f"High ratio of descriptive comments ({descriptive_ratio:.1%})")
        
        # Check for perfect grammar and punctuation
        proper_punctuation = sum(1 for c in comments if c.strip().endswith(('.', '!', '?')))
        if len(comments) > 2 and proper_punctuation / len(comments) > 0.7:
            score += 30
            reasons.append("Comments have proper punctuation (AI characteristic)")
        
        # Check for inline explanatory comments
        inline_comments = [c for c in comments if '//' in c and len(c.strip()) > 20]
        if len(inline_comments) > 3:
            score += 20
            reasons.append("Multiple detailed inline comments")
        
        return {'score': min(score, 100), 'reasons': reasons}
    
    def _check_formatting_consistency(self, code: str) -> Dict:
        """AI code has very consistent formatting"""
        score = 0
        reasons = []
        
        lines = code.split('\n')
        
        # Check indentation consistency
        indents = []
        for line in lines:
            if line.strip():
                indent = len(line) - len(line.lstrip())
                indents.append(indent)
        
        if indents:
            # Check if indentation follows perfect pattern (multiples of same number)
            indent_diffs = [indents[i+1] - indents[i] for i in range(len(indents)-1) if indents[i+1] != indents[i]]
            if indent_diffs:
                common_diff = Counter([abs(d) for d in indent_diffs]).most_common(1)[0]
                if common_diff[1] / len(indent_diffs) > 0.9:
                    score += 35
                    reasons.append(f"Perfect indentation pattern (step: {common_diff[0]})")
        
        # Check brace placement consistency
        opening_braces = re.findall(r'.*\{', code)
        if opening_braces:
            same_line_braces = sum(1 for b in opening_braces if re.search(r'\S.*\{', b))
            consistency = max(same_line_braces, len(opening_braces) - same_line_braces) / len(opening_braces)
            if consistency > 0.95:
                score += 30
                reasons.append(f"Highly consistent brace placement ({consistency:.1%})")
        
        # Check spacing around operators
        operators = re.findall(r'[a-zA-Z0-9_]\s*[+\-*/%=<>!&|]+\s*[a-zA-Z0-9_]', code)
        if operators:
            spaced_ops = sum(1 for op in operators if re.search(r'\s[+\-*/%=<>!&|]+\s', op))
            if len(operators) > 5 and spaced_ops / len(operators) > 0.9:
                score += 25
                reasons.append("Consistent operator spacing")
        
        return {'score': min(score, 100), 'reasons': reasons}
    
    def _check_variable_naming(self, code: str) -> Dict:
        """AI uses descriptive, camelCase/snake_case names consistently"""
        score = 0
        reasons = []
        
        # Extract variable declarations
        var_patterns = [
            r'\b(?:int|float|double|char|long|short|unsigned)\s+([a-zA-Z_][a-zA-Z0-9_]*)',
            r'\bfor\s*\(\s*(?:int|float|double|char)\s+([a-zA-Z_][a-zA-Z0-9_]*)'
        ]
        
        variables = []
        for pattern in var_patterns:
            variables.extend(re.findall(pattern, code))
        
        if not variables:
            return {'score': 50, 'reasons': ['No clear variable declarations found']}
        
        # Check for descriptive names (length > 3, not just i, j, k)
        descriptive_vars = [v for v in variables if len(v) > 3 and v not in ['main', 'argc', 'argv']]
        if len(variables) > 3:
            desc_ratio = len(descriptive_vars) / len(variables)
            if desc_ratio > 0.7:
                score += 40
                reasons.append(f"High ratio of descriptive variable names ({desc_ratio:.1%})")
        
        # Check for camelCase usage (AI often uses this)
        camel_case_vars = [v for v in variables if re.match(r'^[a-z]+[A-Z]', v)]
        if camel_case_vars and len(camel_case_vars) / len(variables) > 0.5:
            score += 30
            reasons.append("Consistent camelCase naming convention")
        
        # Check for very descriptive names
        very_descriptive = [v for v in variables if len(v) > 8]
        if very_descriptive and len(very_descriptive) / len(variables) > 0.3:
            score += 20
            reasons.append("Multiple very descriptive variable names")
        
        # Human students often use single letter or short names
        short_vars = [v for v in variables if len(v) <= 2]
        if len(variables) > 3 and len(short_vars) / len(variables) > 0.5:
            score -= 30
            reasons.append("Many short variable names (human characteristic)")
        
        return {'score': max(0, min(score, 100)), 'reasons': reasons}
    
    def _check_error_handling(self, code: str) -> Dict:
        """AI tends to add comprehensive error handling"""
        score = 0
        reasons = []
        
        # Check for input validation
        scanf_count = len(re.findall(r'scanf\s*\(', code))
        
        # Check for error messages
        error_patterns = [
            r'printf\s*\([^)]*(?:error|Error|ERROR|invalid|Invalid)',
            r'fprintf\s*\(\s*stderr',
            r'perror\s*\(',
        ]
        
        error_handling = sum(len(re.findall(pattern, code)) for pattern in error_patterns)
        
        if scanf_count > 0 and error_handling > 0:
            score += 40
            reasons.append("Input validation with error messages present")
        
        # Check for return value checking
        return_checks = len(re.findall(r'if\s*\([^)]*(?:scanf|malloc|fopen|fread)', code))
        if return_checks > 0:
            score += 35
            reasons.append("Return value checking detected")
        
        # Check for NULL checks
        null_checks = len(re.findall(r'(?:if|while)\s*\([^)]*(?:==|!=)\s*NULL', code))
        if null_checks > 0:
            score += 25
            reasons.append("NULL pointer checks present")
        
        return {'score': min(score, 100), 'reasons': reasons}
    
    def _check_code_structure(self, code: str) -> Dict:
        """AI code has well-organized structure"""
        score = 0
        reasons = []
        
        # Check for function definitions (beyond main)
        functions = re.findall(r'\n(?:int|void|float|double|char)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\([^)]*\)\s*\{', code)
        functions = [f for f in functions if f != 'main']
        
        if len(functions) > 0:
            score += 30
            reasons.append(f"Code modularized with {len(functions)} helper function(s)")
        
        # Check for consistent function ordering
        main_pos = code.find('int main')
        if main_pos > len(code) * 0.5:  # main at the end (good practice)
            score += 20
            reasons.append("main() function at end (good structure)")
        
        # Check for header organization
        includes = re.findall(r'#include\s*[<"].*?[>"]', code)
        if includes:
            include_pos = code.find(includes[0])
            first_code_pos = code.find('int main')
            if include_pos < first_code_pos:
                score += 15
                reasons.append("Headers properly organized at top")
        
        # Check for logical grouping (blank lines between sections)
        sections = code.split('\n\n')
        if len(sections) > 3:
            score += 20
            reasons.append("Code organized into logical sections")
        
        return {'score': min(score, 100), 'reasons': reasons}
    
    def _check_whitespace_perfection(self, code: str) -> Dict:
        """AI code has perfect whitespace usage"""
        score = 0
        reasons = []
        
        lines = code.split('\n')
        
        # Check for trailing whitespace (humans often have this)
        trailing_ws = sum(1 for line in lines if line.rstrip() != line and line.strip())
        if len(lines) > 10 and trailing_ws == 0:
            score += 40
            reasons.append("No trailing whitespace (AI characteristic)")
        
        # Check for consistent blank lines
        blank_line_groups = re.findall(r'\n\n+', code)
        if blank_line_groups:
            # AI typically uses exactly 1 or 2 blank lines consistently
            blank_counts = [len(g) - 1 for g in blank_line_groups]
            most_common = Counter(blank_counts).most_common(1)[0]
            if most_common[1] / len(blank_counts) > 0.8:
                score += 30
                reasons.append("Highly consistent blank line usage")
        
        # Check for space after commas
        commas = re.findall(r',[^\s\n]', code)
        if len(commas) == 0 and ',' in code:
            score += 20
            reasons.append("Perfect spacing after commas")
        
        return {'score': min(score, 100), 'reasons': reasons}
    
    def _check_documentation(self, code: str) -> Dict:
        """AI adds comprehensive documentation"""
        score = 0
        reasons = []
        
        # Check for file header comment
        first_lines = '\n'.join(code.split('\n')[:5])
        if re.search(r'/\*.*?\*/', first_lines, re.DOTALL) or re.search(r'^//.*?$', first_lines, re.MULTILINE):
            score += 25
            reasons.append("File header documentation present")
        
        # Check for function documentation
        functions = re.findall(r'(?://.*?\n|/\*.*?\*/)\s*(?:int|void|float|double)\s+[a-zA-Z_]', code, re.DOTALL)
        if len(functions) > 0:
            score += 35
            reasons.append("Function documentation present")
        
        # Check for inline algorithm explanation
        algorithm_comments = re.findall(r'//.*?(?:algorithm|step|calculate|formula)', code, re.IGNORECASE)
        if len(algorithm_comments) > 0:
            score += 30
            reasons.append("Algorithm explanation comments found")
        
        return {'score': min(score, 100), 'reasons': reasons}
    
    def _check_complexity_clarity(self, code: str) -> Dict:
        """AI balances complexity with clarity"""
        score = 0
        reasons = []
        
        # Count lines of actual code (excluding comments and blank lines)
        code_lines = [l for l in code.split('\n') if l.strip() and not l.strip().startswith('//')]
        
        if len(code_lines) == 0:
            return {'score': 0, 'reasons': ['No code found']}
        
        # Check for complex expressions with good readability
        complex_expressions = re.findall(r'[a-zA-Z0-9_]+\s*[+\-*/%]\s*[a-zA-Z0-9_]+\s*[+\-*/%]', code)
        if complex_expressions:
            # AI tends to break complex expressions or add parentheses
            parenthesized = sum(1 for expr in complex_expressions if '(' in code[max(0, code.find(expr)-10):code.find(expr)+len(expr)+10])
            if len(complex_expressions) > 2 and parenthesized / len(complex_expressions) > 0.5:
                score += 30
                reasons.append("Complex expressions well-parenthesized")
        
        # Check for intermediate variables (AI often uses these for clarity)
        assignments = len(re.findall(r'[a-zA-Z_][a-zA-Z0-9_]*\s*=\s*[^=]', code))
        if len(code_lines) > 10 and assignments / len(code_lines) > 0.3:
            score += 25
            reasons.append("Good use of intermediate variables")
        
        # Check for magic numbers (AI tends to avoid these)
        magic_numbers = re.findall(r'\b(?!0\b|1\b)\d{2,}\b', code)
        if len(magic_numbers) == 0 and len(code_lines) > 15:
            score += 25
            reasons.append("No magic numbers (good practice)")
        
        return {'score': min(score, 100), 'reasons': reasons}
    
    def _check_modern_practices(self, code: str) -> Dict:
        """AI uses modern C practices"""
        score = 0
        reasons = []
        
        # Check for const usage
        if 'const' in code:
            score += 25
            reasons.append("Uses const keyword")
        
        # Check for size_t usage
        if 'size_t' in code:
            score += 20
            reasons.append("Uses size_t type")
        
        # Check for proper header guards (if header file)
        if re.search(r'#ifndef.*\n#define.*\n', code):
            score += 20
            reasons.append("Proper header guards")
        
        # Check for stdint types
        if re.search(r'\b(?:int8_t|int16_t|int32_t|int64_t|uint8_t|uint16_t|uint32_t|uint64_t)\b', code):
            score += 25
            reasons.append("Uses stdint types")
        
        # Check for stdbool
        if 'stdbool.h' in code or re.search(r'\b(?:true|false|bool)\b', code):
            score += 20
            reasons.append("Uses stdbool.h")
        
        return {'score': min(score, 100), 'reasons': reasons}
    
    def _check_blank_line_patterns(self, code: str) -> Dict:
        """AI has specific blank line patterns"""
        score = 0
        reasons = []
        
        lines = code.split('\n')
        
        # Check for blank line before function definitions
        func_pattern = r'(?:int|void|float|double|char)\s+[a-zA-Z_][a-zA-Z0-9_]*\s*\([^)]*\)\s*\{'
        func_matches = list(re.finditer(func_pattern, code))
        
        if len(func_matches) > 1:
            blank_before_func = 0
            for match in func_matches:
                pos = match.start()
                before_text = code[:pos]
                if before_text.endswith('\n\n') or before_text.endswith('\r\n\r\n'):
                    blank_before_func += 1
            
            if blank_before_func / len(func_matches) > 0.7:
                score += 40
                reasons.append("Consistent blank lines before functions")
        
        # Check for blank line after variable declarations
        var_blocks = re.findall(r'(?:int|float|double|char)[^;]+;(?:\s*(?:int|float|double|char)[^;]+;)*', code)
        if var_blocks:
            score += 30
            reasons.append("Organized variable declarations")
        
        return {'score': min(score, 100), 'reasons': reasons}
    
    def _check_comment_placement(self, code: str) -> Dict:
        """AI places comments strategically"""
        score = 0
        reasons = []
        
        # Check for comments before code blocks
        block_comments = len(re.findall(r'//.*?\n\s*(?:if|for|while|switch)\s*\(', code))
        if block_comments > 2:
            score += 35
            reasons.append("Comments before control structures")
        
        # Check for section divider comments
        divider_comments = len(re.findall(r'//\s*[-=]{3,}|/\*\s*[-=]{3,}', code))
        if divider_comments > 0:
            score += 30
            reasons.append("Section divider comments present")
        
        # Check for end-of-line explanatory comments
        eol_comments = len(re.findall(r';\s*//.*?$', code, re.MULTILINE))
        if eol_comments > 3:
            score += 25
            reasons.append("Multiple end-of-line explanatory comments")
        
        return {'score': min(score, 100), 'reasons': reasons}
    
    def _calculate_score(self) -> float:
        """Calculate weighted AI detection score"""
        total_score = 0
        for indicator, weight in self.weights.items():
            if indicator in self.indicators:
                total_score += self.indicators[indicator]['score'] * weight
        return total_score
    
    def _get_verdict(self, percentage: float) -> str:
        """Get human-readable verdict"""
        if percentage >= 75:
            return "HIGHLY LIKELY AI-GENERATED"
        elif percentage >= 60:
            return "LIKELY AI-GENERATED"
        elif percentage >= 40:
            return "POSSIBLY AI-ASSISTED"
        elif percentage >= 25:
            return "LIKELY HUMAN-WRITTEN"
        else:
            return "HIGHLY LIKELY HUMAN-WRITTEN"


def format_report(result: Dict, detailed: bool = True) -> str:
    """Format detection result as readable report"""
    if 'error' in result:
        return f"ERROR: {result['error']}"
    
    report = []
    report.append("=" * 70)
    report.append(f"AI CODE DETECTION REPORT")
    report.append("=" * 70)
    report.append(f"File: {result['file']}")
    report.append(f"AI Likelihood: {result['ai_percentage']}%")
    report.append(f"Verdict: {result['verdict']}")
    report.append("=" * 70)
    
    if detailed:
        report.append("\nDETAILED ANALYSIS:")
        report.append("-" * 70)
        
        for indicator, data in result['indicators'].items():
            indicator_name = indicator.replace('_', ' ').title()
            report.append(f"\n{indicator_name}: {data['score']}/100")
            if data['reasons']:
                for reason in data['reasons']:
                    report.append(f"  • {reason}")
    
    report.append("\n" + "=" * 70)
    return '\n'.join(report)


def main():
    parser = argparse.ArgumentParser(
        description='AI Code Detector for C Programming - Detects AI-generated code patterns',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  %(prog)s code1.c                    # Analyze single file
  %(prog)s code1.c code2.c code3.c    # Analyze multiple files
  %(prog)s *.c                        # Analyze all C files
  %(prog)s --batch *.c                # Batch mode with summary
  %(prog)s --json code1.c             # Output as JSON
        """
    )
    
    parser.add_argument('files', nargs='+', help='C source file(s) to analyze')
    parser.add_argument('--json', action='store_true', help='Output results as JSON')
    parser.add_argument('--batch', action='store_true', help='Batch mode with summary statistics')
    parser.add_argument('--brief', action='store_true', help='Brief output (no detailed breakdown)')
    parser.add_argument('--output', '-o', help='Save report to file')
    
    args = parser.parse_args()
    
    detector = CCodeAIDetector()
    results = []
    
    # Analyze all files
    for filepath in args.files:
        if not os.path.exists(filepath):
            print(f"Warning: File not found: {filepath}", file=sys.stderr)
            continue
        
        if not filepath.endswith('.c'):
            print(f"Warning: Skipping non-C file: {filepath}", file=sys.stderr)
            continue
        
        result = detector.analyze_file(filepath)
        results.append(result)
    
    if not results:
        print("Error: No valid C files to analyze", file=sys.stderr)
        return 1
    
    # Generate output
    output_lines = []
    
    if args.json:
        output_lines.append(json.dumps(results, indent=2))
    elif args.batch:
        # Batch summary
        output_lines.append("=" * 70)
        output_lines.append("BATCH ANALYSIS SUMMARY")
        output_lines.append("=" * 70)
        output_lines.append(f"Total files analyzed: {len(results)}")
        
        percentages = [r['ai_percentage'] for r in results if 'ai_percentage' in r]
        if percentages:
            output_lines.append(f"Average AI likelihood: {sum(percentages)/len(percentages):.2f}%")
            output_lines.append(f"Highest AI likelihood: {max(percentages):.2f}%")
            output_lines.append(f"Lowest AI likelihood: {min(percentages):.2f}%")
        
        output_lines.append("\n" + "-" * 70)
        output_lines.append("INDIVIDUAL RESULTS:")
        output_lines.append("-" * 70)
        
        for result in results:
            if 'error' not in result:
                filename = os.path.basename(result['file'])
                output_lines.append(f"{filename:30s} {result['ai_percentage']:6.2f}%  {result['verdict']}")
        
        output_lines.append("=" * 70)
    else:
        # Individual detailed reports
        for result in results:
            output_lines.append(format_report(result, detailed=not args.brief))
            if len(results) > 1:
                output_lines.append("\n")
    
    output_text = '\n'.join(output_lines)
    
    # Output to file or stdout
    if args.output:
        with open(args.output, 'w') as f:
            f.write(output_text)
        print(f"Report saved to: {args.output}")
    else:
        print(output_text)
    
    return 0


if __name__ == '__main__':
    sys.exit(main())
