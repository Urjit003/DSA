# for i in {1..6}; do
#     echo "iteration $i"
# done

#WHILE
    # count=1 
    # while [ $count -le 10 ]; do
    #     echo "counter $count"
    #     ((count++))
    # done

#functions
    # greet() {
    #     echo "Greetings , $1 !"
    # }

    # greet "urjit"
#FILE OPERATIONS

    # echo "this is a sample text" > sample.txt

    # while read line;do
    #     echo $line
    # done < sample.txt

#command substitution
    # current_date=``
    # echo $current_date


#function to display even numbers 

display_even_for() {
    echo "Even numbers using for loop"
    for ((i = 2; i <= $1; i+=2));do
        echo -n "$i "P
    done
    echo   
}

display_odd_for() {
    echo "Even numbers using for loop"
    for ((i = $1;i <= $2;i+=2));do
        echo -n "$i "
    done
    echo   
}

check_for_digit() {
    read -p "Enter a string : " input
    if [[ "$input" =~ ^[0-9]+$ ]]; then
        echo "the $input contains only 1 digit"
    else 
        echo "the $input doesnt contain only digit"
    fi
}

# reverse six digit number
    # reverse_number() {
    #     local number="$1"
    #     local reversed_number=""
        
    #     while [ -n "$number" ]; do
    #         # Extract the last digit
    #         digit="${number: -1}"
    #         # Append it to the reversed number
    #         reversed_number="$reversed_number$digit"
    #         # Remove the last digit from the original number
    #         number="${number%?}"
    #     done
        
    #     echo "$reversed_number"
    # }

    # reverse_number "$1"

best_worst_salesman(){
    # Check if the input file exists
    if [ ! -f "sales.dat" ]; then
        echo "Error: File 'sales.dat' not found."
        exit 1
    fi

    # Initialize variables
    total_sales=0
    declare -A product_sales
    declare -A salesman_sales
    best_salesman=""
    worst_salesman=""
    highest_sold_product=""
    max_sales=0
    min_sales=0

    # Process the file using awk
    awk -F ': ' '
    {
        # Get the sales details
        salesman=$1
        product1=$2
        product2=$3
        product3=$4

        # Calculate total sales for the company
        total_sales += product1 + product2 + product3

        # Calculate sales per product
        product_sales["Product1"] += product1
        product_sales["Product2"] += product2
        product_sales["Product3"] += product3

        # Calculate sales per salesman
        salesman_sales[salesman] = product1 + product2 + product3
    }

    END {
        # Print total sales
        printf("Total sales of the company: %d\n", total_sales)

        # Determine the highest sold product
        highest_sold_product = "Product1"
        max_sales = product_sales["Product1"]
        for (product in product_sales) {
            if (product_sales[product] > max_sales) {
                highest_sold_product = product
                max_sales = product_sales[product]
            }
        }
        printf("Highest sold product: %s with %d sales\n", highest_sold_product, max_sales)

        # Determine the best and worst salesman
        for (salesman in salesman_sales) {
            if (salesman_sales[salesman] > max_sales) {
                best_salesman = salesman
                max_sales = salesman_sales[salesman]
            }
            if (min_sales == 0 || salesman_sales[salesman] < min_sales) {
                worst_salesman = salesman
                min_sales = salesman_sales[salesman]
            }
        }
        printf("Best salesman: %s with %d sales\n", best_salesman, max_sales)
        printf("Worst salesman: %s with %d sales\n", worst_salesman, min_sales)
    }
    ' sales.dat
}
# a=20
# c=$((a+20))
# echo $c

pattern() {
 #!/bin/bash

    for ((i=1; i<=5; i++)); do
        for ((j=1; j<=i; j++)); do
            echo -n "| "
        done
        echo "_"
    done

}
reverse() {

    read -p "Enter a six-digit number: " num

    if ! [[ "$num" =~ ^[0-9]{6}$ ]]; then
        echo "Invalid input. Please enter a six-digit number."
        exit 1
    fi

    reverse=""
    for ((i=${#num}-1; i>=0; i--)); do
        reverse="${reverse}${num:$i:1}"
    done

    echo "Reversed number: $reverse"
    
    
}

STUDENTS_FILE() {
    STUDENTS_FILE="students.txt"

    add_student() {
        read -p "Enter student name: " name
        read -p "Enter marks in subject 1: " sub1
        read -p "Enter marks in subject 2: " sub2
        read -p "Enter marks in subject 3: " sub3
        echo "$name, $sub1, $sub2, $sub3" >> $STUDENTS_FILE
    }

    display_marksheet() {
        while IFS=", " read -r name sub1 sub2 sub3; do
            echo "Name: $name"
            echo "Subject 1: $sub1"
            echo "Subject 2: $sub2"
            echo "Subject 3: $sub3"
            echo
        done < $STUDENTS_FILE
    }

    add_student
    display_marksheet
}

echo "3 + 4" | bc
