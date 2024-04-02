def NionAlgorithm():
    inputFileName = input("Please enter your input file name")
    outputFileName = input("Please enter your output file name")
    inputFile = open(inputFileName, "r")
    outputFile = open(outputFileName, "a")
    for line in inputFile:
        if "gmail" in line or "yahoo" in line:
            data = line.split(':')
            if len(data) >= 4:  # Check if line has at least 3 parts after splitting
                outputFile.write(data[len(data) - 2] + ":" + data[len(data) - 1] + "\n")  # Add "\n" for line break
    inputFile.close()
    outputFile.close()


def PhotoResizers():
    from PIL import Image
    import os

    # Define paths to input and output folders
    input_folder = input("Input Folder Name  : ")
    output_folder = input("Output Folder Name : ")
    os.makedirs(output_folder, exist_ok=True)

    # Define the new size (width, height) or scale factor
    width = int(input("Width size : "))
    height = int(input("Height size : "))
    new_size = (width, height)  # (width, height)

    # Iterate over all files in the input folder
    for filename in os.listdir(input_folder):
        if filename.endswith((".jpg", ".jpeg", ".png")):  # Process only image files
            # Open the image file
            input_image_path = os.path.join(input_folder, filename)
            image = Image.open(input_image_path)
            
            # Resize the image
            resized_image = image.resize(new_size)
            
            # Construct the output path
            output_image_path = os.path.join(output_folder, filename)
            
            # Save the resized image
            resized_image.save(output_image_path)
            
            # Close the image object
            image.close()

    print("Resizing and saving complete.")