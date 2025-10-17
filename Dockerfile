FROM openjdk:17-slim
WORKDIR /app
COPY . .
RUN javac CheckFile.java
ENTRYPOINT ["java", "CheckFile"]