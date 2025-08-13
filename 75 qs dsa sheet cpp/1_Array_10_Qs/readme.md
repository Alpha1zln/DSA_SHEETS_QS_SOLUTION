## Week 2 ... 

Added TC amd SC in all 10 qs of arr    


## Git codes for pushing to github, for week 2 *************  

some git ques ---  
i have 10 folders for leetcode 75 q soltn ... 
partial soltn in all folders ... as all q related to arr i solved, then i want to push arr folder only .. not other folders [parital work in them]
how to push only 1 folder out of 10 to github
that 1 folder old files to be deleted and new files to be added 
also a new br to be created as week2


guidance: *************  
Got it ✅ — you basically want:  
Only update one folder (say arrays/)  
Delete the old files for that folder on GitHub and replace with new ones  
Ignore other folders (partial work stays untouched in GitHub)  
Do this in a new branch (week2)  

### Here’s the clean, step-by-step way:  

1️⃣ Create and switch to the new branch  
bash
Copy
Edit
```
git checkout -b week2
```
This makes a new branch starting from your current state.  

2️⃣ Delete the old folder from Git tracking  
This removes the old files from the repo (in this branch only):  

bash
Copy
Edit
```
git rm -r path/to/arrays
```

3️⃣ Add your new folder  
Copy your updated arrays/ folder into the repo (if it’s not already there), then:  

bash
Copy
Edit
```
git add path/to/arrays
```

4️⃣ Commit  
bash
Copy
Edit
```
git commit -m "Update arrays folder with new solutions for week 2"
```

5️⃣ Push this branch to GitHub  
bash
Copy
Edit
```
git push origin week2
```

6️⃣ Result  
On GitHub main branch → old state, untouched.  

On GitHub week2 branch → only your updated arrays folder changes.  

********

💡 Extra Notes  

If you really only want to commit this folder and ignore all other changes in your working directory,   
you can commit just that folder without touching others:  

bash
Copy
Edit
```
git add path/to/arrays
git commit -m "Update arrays folder"
```
That way, unrelated partial work won’t get into the commit.  

************  


