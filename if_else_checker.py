def check_indentation(code_lines):
    """Check for consistent indentation (no mixing tabs and spaces)"""
    for line in code_lines:
        if line.strip():  # Skip empty lines
            if '\t' in line and ' ' in line[:line.find(line.lstrip()[0])]:
                return False
    return True

def check_colon(line):
    """Verify colon exists after if/elif/else"""
    return ':' in line.split('#')[0]  # Ignore comments

def check_parentheses(line):
    """Check balanced parentheses in condition"""
    condition = line.split(':')[0]
    return condition.count('(') == condition.count(')')

def analyze_if_else(lines):
    has_if = False
    base_indent = -1

    for i, line in enumerate(lines, 1):
        stripped = line.strip()
        
        # Skip empty lines and comments
        if not stripped or stripped.startswith('#'):
            continue
            
        # Check if line
        if stripped.startswith('if'):
            has_if = True
            base_indent = len(line) - len(line.lstrip())
            
            if not check_colon(line):
                print(f"Line {i}: Syntax Error → Missing colon after 'if'")
                return
            
            if not check_parentheses(line):
                print(f"Line {i}: Syntax Warning → Unbalanced parentheses in 'if' condition")
                
        # Check elif
        elif stripped.startswith('elif'):
            if not has_if:
                print(f"Line {i}: Syntax Error → 'elif' without preceding 'if'")
                return
            
            current_indent = len(line) - len(line.lstrip())
            if current_indent != base_indent:
                print(f"Line {i}: Syntax Error → 'elif' not aligned with 'if'")
                return
            
            if not check_colon(line):
                print(f"Line {i}: Syntax Error → Missing colon after 'elif'")
                return
                
        # Check else
        elif stripped.startswith('else'):
            if not has_if:
                print(f"Line {i}: Syntax Error → 'else' without preceding 'if'")
                return
            
            current_indent = len(line) - len(line.lstrip())
            if current_indent != base_indent:
                print(f"Line {i}: Syntax Error → 'else' not aligned with 'if'")
                return
            
            if not check_colon(line):
                print(f"Line {i}: Syntax Error → Missing colon after 'else'")
                return

    if not has_if:
        print("Syntax Error → No 'if' statement found")
        return

    print("✅ Valid if-else syntax!")

def main():
    print("Python if-else Syntax Analyzer")
    print("Enter your code (blank line to finish):")
    
    lines = []
    while True:
        try:
            line = input()
            if line == "" and lines and lines[-1] == "":
                break
            lines.append(line)
        except EOFError:
            break
    
    # Remove trailing empty lines
    while lines and lines[-1] == "":
        lines.pop()
    
    if not lines:
        print("Error: No input provided")
        return
    
    # Check indentation first
    if not check_indentation(lines):
        print("Syntax Error → Mixed tabs and spaces in indentation")
        return
    
    analyze_if_else(lines)

if __name__ == "__main__":
    main()