import os

# Directory containing the .c files
directory = "./"

# Output file
output_file = "m_files.txt"

# Open the output file in write mode
with open(output_file, "w") as out_file:
    # Iterate over all files in the directory
    for filename in os.listdir(directory):
        if filename.endswith(".c"):
            # Write the filename to the output file
            out_file.write("/* " + filename + " */\n\n")
            
            # Open the current file and read its content
            with open(os.path.join(directory, filename), "r") as in_file:
                content = in_file.read()
            
            # Write the content to the output file
            out_file.write(content)
            
            # Add two empty lines
            out_file.write("\n\n")

