#!/bin/bash

# Set your GitHub repository URL and branch name
# REPO_URL="master"
BRANCH="master"  # or "master" depending on your default branch

# Function to add, commit, and push changes

push_to_github() {
# Add all new and modified files
	git add --all 

# Prompt user to enter a commit message
	read -p "Enter commit message: " commit_msg

# Commit with the provided commit message
	git commit -m "$commit_msg"

# Push changes to GitHub
	git push origin "$BRANCH"
}

# Main script execution
echo "Starting to push changes to GitHub..."

# Check if the current directory is a Git repository
if [ ! -d .git ]; then
echo "Error: This directory is not a Git repository."
exit 1
fi

# Set remote URL to your GitHub repository
# git remote set-url origin "$REPO_URL"

# Call function to add, commit, and push changes
push_to_github

echo "Push to GitHub completed."

