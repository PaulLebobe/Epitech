folder("Whanos base images") {
	description("Images of whanos.")
}

folder("Projects") {
    description("Projects of whanos.")
}

languages = ["c", "java", "javascript", "python", "befunge"]

languages.each { language ->
	freeStyleJob("Whanos base images/whanos-$language") {
		steps {
			shell("docker build /images/$language -f /images/$language/Dockerfile.base -t whanos-$language")
		}
	}
}

freeStyleJob('link-project') {
    parameters {
        stringParam('GITHUB_NAME', '', 'GitHub repository owner/repo_name (e.g.: "Epitech")')
        stringParam('DISPLAY_NAME', '', 'Display name for the job')
    }
    steps {
        dsl {
            text('''
                freeStyleJob("$DISPLAY_NAME") {
                    wrappers {
                        preBuildCleanup ()
                    }
                    scm {
                        github("$GITHUB_NAME")
                    }
                    triggers {
                        scm('* * * * *')
                    }
                    steps {
                        shell('make fclean')
                        shell('make')
                        shell('make tests_run')
                        shell('make clean')
                    }
                }
            ''')
        }
    }
}