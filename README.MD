# DSA SHEETS SOLUTIONS

Welcome to my DSA preparation repository!  
This repo contains solutions to top coding interview problems organized by popular DSA sheets.

##  Included Sheets

- ✅ **LeetCode Sheets**  
  - 75 Questions  
  - 150 Questions  

- ✅ **Striver's Sheet**  
  - 191 Questions (Full Sheet)  
  - 79 Questions (Top Questions)




*******************************************************************************************************
* HOW TO USE GITHUB ---

…or create a new repository on the command line
```
echo "# DSA_SHEETS_QS_SOLUTION" >> README.md

git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/Alpha1zln/DSA_SHEETS_QS_SOLUTION.git
git push -u origin main
```

…or push an existing repository from the command line
```
git remote add origin https://github.com/Alpha1zln/DSA_SHEETS_QS_SOLUTION.git
git branch -M main
git push -u origin main
```

*******************************************************************************************************
HOW TO UPLOAD CODES FROM LAPTOP TO GITHUB ---

🗂️ Setup Summary:
You have a main folder: DSA_Sheets (on both laptop & GitHub).
Inside DSA_Sheets are 10 subfolders (e.g., Arrays, Strings, etc.)
You want to weekly add 10 new solutions and push them to GitHub.

✅ Step-by-step Guide:

✅ 1. Initial Git Setup (Only once)
If not already done:

cd path/to/DSA_Sheets   # Go inside your main folder
```
git init
git remote add origin https://github.com/your-username/DSA_Sheets.git
git branch -M main
```
Replace the URL with your actual GitHub repo link.

✅ 2. Weekly Routine to Add & Push Code
Each week:
✅ Add your 10 files in their respective subfolders.

✅ Stage the new files:
```
git add .         # Adds all new/modified files
```
You can also do:
```
git add Arrays/q1.cpp if you want to add specific files.
```

✅ Commit your weekly update:
```
git commit -m "Week 3: Added 10 new DSA solutions"
```

✅ Push to GitHub:
```
git push origin main
```

💡 Pro Tip: Avoid pushing unnecessary files
Create a .gitignore in DSA_Sheets folder with:
*.exe
*.out
*.log
*.class
.DS_Store
__pycache__/

Then run:
```
git rm -r --cached .
git add .
git commit -m "Applied .gitignore"
```

✅ Optional: Weekly Branches (for practice)
If you want to maintain weekly progress:
```
git checkout -b week_3     # Create new branch
git add .
git commit -m "Week 3 solutions"
git push -u origin week_3
```

And later:
git checkout main
git merge week_3
git push origin main

📌 Done!
Your weekly uploads are now fully Git-enabled — just remember to add, commit, and push every time you add new solutions.


*******************************************************************************************************
***** other ways --- using branch ---

Sure! Here's a clean and complete step-by-step guide based on your setup:

✅ SCENARIO:
You already have a main folder on your PC (DSA_Sheets) with 10 subfolders, and some files.
You've already created a GitHub repo called DSA_Sheets.

You want to:
✅ Create a new branch like week1
✅ Push your local code to that branch
✅ Later, merge it into main on GitHub via a Pull Request
✅ Exclude .exe files from being pushed
✅ FINAL GUIDE (Only once: First Time Setup)

📁 Step 1: Navigate to Your Local Folder
cd path/to/DSA_Sheets

🔧 Step 2: Initialize Git & Connect to GitHub
```
git init
git remote add origin https://github.com/<your-username>/DSA_Sheets.git
```

and one should create - 
create readme.md and .gitignore files in repo.
Readme.md => Should have project details of repo
.gitignore file => Contents of it mentioned below [files that user doesn't want to be uploaded on git from local laptop]

optional ...              
Then run:
```
git pull origin main --allow-unrelated-histories
```
This pulls the GitHub repo (with README etc.) into your local project without deleting your local files.


                             
📝 Step 3: Create a .gitignore File
To ignore .exe files and other junk:
echo "*.exe" >> .gitignore
echo "*.out" >> .gitignore
echo "*.log" >> .gitignore
Optional: Open and manually edit .gitignore for more rules.


                             
🌱 Step 4: Create and Switch to a New Branch (week1)
```
git checkout -b week1
```

➕ Step 5: Add and Commit Your Local Files
```
git add .
git commit -m "Week 1: Initial upload of DSA solutions"
```

☁️ Step 6: Push to GitHub (to the week1 branch)
```
git push -u origin week1
```

✅ Your code will now appear under the week1 branch on GitHub.
                             
✅ FOR LATER WEEKS
Each week:
Add new files in local PC
Run:
```
git add .
git commit -m "Week 2: Added 10 more questions"
git push origin week1
```

Or you can create a new branch each week:
```
git checkout -b week2
```
-then repeat push steps
                             
🔁 OPTIONAL: Merge week1 into main on GitHub
Go to GitHub
Click “Compare & Pull Request”
Merge week1 → main

***********************************************************************************************
❓ EXTRA: What if README already exists in GitHub?

If your GitHub repo has a README and your local repo is new, run:
```
git pull origin main --allow-unrelated-histories
```

Then resolve any merge messages, commit, and push.

✅ Run this command only once, and only if:
You already created a GitHub repo with a README file or LICENSE or any default file.

And your local folder (PC) already has code, but you did not clone the repo — instead, you did git init directly in your local folder.

🧠 Why is this needed?
Because Git sees your local history and the remote GitHub history as two unrelated histories. So you must allow Git to merge them manually.

🕒 WHEN to run it?
After you do:
```
git init
git remote add origin https://github.com/<username>/DSA_Sheets.git
```

Then run:
```
git pull origin main --allow-unrelated-histories
```
This pulls the GitHub repo (with README etc.) into your local project without deleting your local files.

✅ Then continue normally:
```
git add .
git commit -m "First merge with GitHub README"
git push -u origin main
```

or (if using week1 branch):
```
git checkout -b week1
git push -u origin week1
```

Let me know if you want a clean cheat sheet for this full setup.

***********************************************************************************************
***********************
.gitignore file ****
Yes, you can and should manually create the .gitignore file in your repo folder — both locally and on GitHub if needed.

✅ How to create .gitignore manually:

Option 1: Locally in your folder (Recommended)
Go to your main folder (e.g., DSA_Sheets)
Create a .gitignore file using a text editor:
On Windows: Right-click → New → Text Document → Rename to .gitignore

Or use command line:
```
cd DSA_Sheets
touch .gitignore      # Linux/Mac or Git Bash on Windows
```

Open .gitignore and paste:
*.exe
*.out
*.log
*.class
.DS_Store
__pycache__/
Save and close.

Then run in terminal:
```
git rm -r --cached .
git add .
git commit -m "Apply .gitignore rules"
```

Option 2: Directly on GitHub (if no local file yet)
Go to your GitHub repo.
Click Add file → Create new file.
Name the file .gitignore

Paste the ignore rules:
*.exe
*.out
*.log
*.class
.DS_Store
__pycache__/
Click Commit new file.

🎯 Why .gitignore matters:
It ensures that unnecessary or junk files like .exe, .class, or Python cache folders never get pushed to your GitHub repo.

***********************************************************************************************
