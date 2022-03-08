FROM jenkins/jenkins:lts

ENV JAVA_OPTS -Djenkins.install.runSetupWizard=false
ENV CASC_JENKINS_CONFIG /var/jenkins_home/casc.yaml

COPY jenkins/plugins.txt /var/plugins.txt
COPY jenkins/job_dsl.groovy /var/jenkins_conf/job_dsl.groovy
COPY images images

ENV JENKINS_ADMIN_PASSWORD "admin"

USER root
RUN /usr/local/bin/install-plugins.sh < /var/plugins.txt
COPY jenkins/casc.yaml /var/jenkins_home/casc.yaml
